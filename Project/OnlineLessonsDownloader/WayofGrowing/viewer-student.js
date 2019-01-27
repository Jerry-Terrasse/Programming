var imagePath = "image";
// 弹出提示框模板
var template_alert = '' +
	'<div class="alert"> 									' +
	'	<span class="text"></span>																' +
	'	<a class="alert-link" href="#"></a>												       ' +
	'</div>';
//题目提示框模板
var question_alert = '' +
	'<div class="question-alert"> 									' +
	'	<span class="text"></span>																' +
	'</div>';
//金币红包模板                             
var template_red_packet = '' +
	'<div class="red_packet"> 								' +
	'	<div class="mask"></div> 							' +
	'	<div class="bg"> 									' +
	'		<div class="close-btn"></div> 					' +
	'		<div class="title"></div> 						' +
	'		<div class="sub-title">获得金币</div> 			' +
	'		<div class="score"><i></i></div> 				' +
	'		<div class="audio" style="display:none;"><audio controls="controls" id="red_packet_audio" ></audio></div> 				' +
	'	</div> 												' +
	'</div>';
//
var iframe = '' +
	'<div class="in-iframe">' +
	'</div>';
//
var sudokuIframe = '' +
	'	<div class="sudoku-iframe">' +
	'		<iframe src= "'+server+'/sudoku/openSudoku?courseId='+serverObj.courseId+'&knowledgeId='+serverObj.knowledgeId+'">' +
	'		</iframe>' +
	'	</div>';
//
function createIframe() {
	return $(iframe).clone();
}

/*
 *标志函数
 */
 function sign(num,func) {
			var x = 1;
			return function(s) {
				if(x == num) func(s);
					else x++;
			}
		}
/**
 * 判断浏览器是否为微信浏览器
 * 
 * @returns {Boolean}
 */
function isWeiXin() {
	var ua = navigator.userAgent.toLowerCase();
	if (ua.match(/MicroMessenger/i) == "micromessenger") {
		return true;
	} else {
		return false;
	}
}
/* 聊天框缩进 */

jQuery.fn.slideRightHide = function(speed, callback) {
	this.animate({
		width: "0",
		borderLeftWidth: "3px"
	}, speed, callback);
};
jQuery.fn.slideRightShow = function(speed, callback) {
	this.animate({
		width: "20%",
		borderLeftWidth: "1px"
	}, speed, callback);
};
jQuery.fn.slideLeftShow = function(speed, callback) {
	this.animate({
		marginRight: "3px"
	}, speed, callback);
};
jQuery.fn.slideLeftHide = function(speed, callback) {
	this.animate({
		marginRight: "20%"
	}, speed, callback);
};

function turnRight() {
	setTimeout(function() {
		$("#chat").addClass("chat-border");
		$("#chat").stop(true, true).slideRightHide(0);
		$("#window").stop(true, true).slideLeftShow(0);
		$("#chat-draw").removeClass("chat-draw-turnR");
		$("#chat-draw").addClass("chat-draw-turnL");
		$('#chat-draw').css('marginLeft', '-13px');
	}, 100)
}

function turnLeft() {
	setTimeout(function() {
		$("#window").stop(true, true).slideLeftHide(0);
		$("#chat").stop(true, true).slideRightShow(0);
		$("#chat-draw").removeClass("chat-draw-turnL");
		$("#chat-draw").addClass("chat-draw-turnR");
		$('#chat-draw').css('marginLeft', '-11px');
		setTimeout(function() {
			$("#chat").removeClass("chat-border");
		}, 100)
	}, 100);
}
$("#chat-draw").click(function() {
	if ($("#chat").width() !== 0)
		turnRight();
	else
		turnLeft();
})

/**
 * 判断是否为pc端j
 * @returns {Boolean}
 */
function isMobile() {
	return LMC.tools.isMobile();
}
/**
 * 展示题目警告框
 * 
 * @param text
 */
function showCustomAlert(text,target) {
	var _target = target || 'body';
	$('.question-alert').remove();
	var $alert = $(question_alert).clone();
	$alert.find('.text').text(text);
	$(_target).append($alert);
	setTimeout(function() {
		$alert.animate({
			opacity: '0'
		}, 2000, function() {
			$alert.remove();
		});
	}, 500);
}

/**
 * 展示警告框
 * 
 * @param text
 */
function showAlert(text) {
	$('.alert').remove();
	var $alert = $(template_alert).clone();
	$alert.find('.text').text(text);
	$('body').append($alert);
	setTimeout(function() {
		$alert.animate({
			opacity: '0'
		}, 3000, function() {
			$alert.remove();
		});
	}, 1000);
}

// 展示红包
function showRedPacket(score, title) {
	if (!score || isNaN(score)) {
		return false;
	}
	$('.red_packet').remove();

	var time = 3;
	var $redPacket = $(template_red_packet).clone();
	$redPacket.find('.title').text(title);
	$redPacket.find('.score i').text(score);
	$redPacket.find('.close-btn').click(function() {
		$redPacket.remove();
	});
	$('body').append($redPacket);


	$redPacket.find('.close-btn').text(time);
	setInterval(function() {
		if (time <= 0) {
			$redPacket.remove();
		} else {
			$redPacket.find('.close-btn').text(time--);
		}
	}, 1000);

	var audio = document.getElementById("red_packet_audio");

	var audioUrl = resourcesPath + '/audio/red_packet_bg_audio.mp3';
	if (window.WeixinJSBridge) {
		LMC.playAudio({
			status: 'play',
			url: audioUrl,
			loop: false
		});
	} else {
		LMC.playAudio({
			status: 'play',
			url: audioUrl,
			loop: false
		});
	}
}


var isOverMsg = false; //鼠标是否防止在消息框上

var barrage = false;

var commentIsShow = false;

var isScroll = false;

var messageCount = 0;

var time = 0;

var speakingStatus = false;

var playerStatus = 0; //上课状态编码 1未开始 2上课 3休息 4下课

var oneEvent = 0; //轮询开始初始化状态

var systemTime = 0; //轮询记录服务器时间

var liveStartTime = 0;//上课时间

var classEndTime = 0; //课程预设结束时间

var realStartTime = 0//课程实际开始时间

var sudokuStatus = 0;//数独状态

var signSuduku =  sign(2,function(){$('.pop-start').show();});

/**
 * 毫秒转消息显示的时间
 * @param millisecond
 */
function convertMillisecondToTimeHtml(millisecond) {
	if (!millisecond || millisecond < 0) {
		return '';
	}
	var current = new Date().getTime();
	var time = new Date(millisecond);
	var h = time.getHours(); //时
	var mm = time.getMinutes(); //分
	var s = time.getSeconds(); //秒
	return h + ':' + mm;
};

/**
 * 毫秒转消息显示的时间
 * @param millisecond
 */
function convertMillisecondToHtml(millisecond) {
	if (!millisecond || millisecond < 0) {
		return '';
	}

	var current = new Date().getTime();


	var time = new Date(millisecond);
	var y = time.getFullYear(); //年
	var m = time.getMonth() + 1; //月
	var d = time.getDate(); //日
	var h = time.getHours(); //时
	var mm = time.getMinutes(); //分
	var s = time.getSeconds(); //秒
	h = h < 10 ? ("0" + h) : h;
	mm = mm < 10 ? ("0" + mm) : mm;
	if ((current - millisecond) > 86400000 && (current - millisecond) < 172800000) {
		//昨天的消息
		return '昨天' + h + ':' + mm;
	} else if ((current - millisecond) > 172800000) {
		//昨天的消息
		return m + '-' + '' + d + ' ' + h + ':' + mm;
	} else {
		return h + ':' + mm;
	}
};

/**
 * 毫秒转时分秒
 * @param mtime
 * @returns {String}
 */
function mtimeToHMsString(mtime) {
	var hh = parseInt(mtime / 1000 / 60 / 60 % 24, 10);
	var mm = parseInt(mtime / 1000 / 60 % 60, 10);
	var ss = parseInt(mtime / 1000 % 60, 10);
	// 		dd = dd<10?("0" + dd):dd;   //天  
	hh = hh < 10 ? ("0" + hh) : hh; //时  
	mm = mm < 10 ? ("0" + mm) : mm; //分  
	ss = ss < 10 ? ("0" + ss) : ss; //秒 
	return hh + ':' + mm + ':' + ss;
}

/**
 * 毫秒转时分
 */
function mtimeToMsString(mtime) {
	var mm = parseInt(mtime / 1000 / 60 % 60, 10);
	var ss = parseInt(mtime / 1000 % 60, 10);
	mm = mm < 10 ? ("0" + mm) : mm; //分  
	ss = ss < 10 ? ("0" + ss) : ss; //秒
	return mm + ':' + ss;
}
/**
 * 毫秒转时分
 */
function mtimeToMsObject(mtime) {
	var mm = parseInt(mtime / 1000 / 60 % 60, 10);
	var ss = parseInt(mtime / 1000 % 60, 10);
	mm = mm < 10 ? ("0" + mm) : mm; //分  
	ss = ss < 10 ? ("0" + ss) : ss; //秒
	return {minute:mm,second:ss}
}
/**
 * 显示消息
 */
function showMsgItem(msg) {
	var $items = $('#chat-items');
	if (messageCount++ > 120) {
		$items.find('.chat-message').eq(0).remove();
		$('.chat-alert').show();
	}
	var maxDisplayMsgCount = 4;
	var item = $("<div></div>");

	item.attr('class', 'chat-message left');

	//渲染头像
	portraitElm = $("<img/>");
	portraitElm.attr('class', 'message-avatar');
	portraitElm.attr('src', decodeURIComponent(msg.headerUrl) || (imagePath + '/placeholder/user_portrait_none.png'));

	//渲染消息内容
	messageDiv = $("<div></div>");
	messageDiv.attr('class', 'message');

	//渲染用户名
	nickNameSpan = $("<a />");
	nickNameSpan.attr('class', 'message-author');

	//渲染到达时间
	arrivaltimeSpan = $("<span></span>");
	arrivaltimeSpan.attr('class', 'message-date');

	arrivaltimeSpan.html(convertMillisecondToHtml((msg.imgTime || msg.time) * 1000));


	var role = msg.role;
	var roleText = role == 'student' || role == 'coach' ? '' : role == 'zj' ? '[班主任]' : '[教师]';

	var colorList = ['red', 'green', 'blue', 'org','white'];
	var msgColorList =['white','org'];
	if (msg.role == 'student') {var index = 2,msgIndex = 0;}
	else if (msg.role == 'teacher' || msg.role == 'zj') {var index = 3,msgIndex = 0;}
	else {var index = 2,msgIndex = 0;}
	var color = colorList[index];
	var msgColor = msgColorList[msgIndex]
	nickNameSpan.attr('class', 'user-name-' + color);
	item.attr('role', role);
	nickNameSpan.html(roleText + msg.fromAccountNick);

	contentSpan = $("<span></span>");
	contentSpan.attr('class', 'message-content user-content-' + msgColor);
	if (!msg.icon) {
		var arr = msg.content.split('/*/');
		contentSpan.html(arr[1]);
	} else contentSpan.html(msg.content);
	messageDiv.append(nickNameSpan);
	messageDiv.append(arrivaltimeSpan);
	messageDiv.append(contentSpan);

	item.append(portraitElm);
	item.append(messageDiv);

	item.find('.message-avatar').on('error', function() {
		var defaultImg = imagePath + '/placeholder/user_portrait_none.png';
		var src = $(this).attr('src');
		if (src != defaultImg) {
			$(this).attr('src', defaultImg);
		}
	});
	$items.append(item);


	if (!isOverMsg && !isScroll && LMC.getStatus().historyMsgLoadComplete) {
		/*isScroll = true;*/
		var _items = $items.get(0);
		$items.animate({
			'scrollTop': _items.scrollHeight
		}, 300, function() {
			isScroll = false;
		});
	}
}

/**
 * 发送消息
 */
function sendTextMsg() {
	LMC.sendTextMsg($('#send_msg_text').val());
	$('#send_msg_text').focus();
}

/**
 * 显示弹幕消息
 */
function showBarrageItem(msg) {
	if (!isOverMsg && LMC.getStatus().historyMsgLoadComplete) {
		if (barrage == 'on' && $('#barrage_input').is(':checked')) {
			var role = msg.role;
			var roleText = role == 'student' || role == 'coach' ? '' : role == 'zj' ? '[班主任]' : '[教师]';
			if (msg.content.length < 100) {
				var arr = msg.content.split('/*/');
				var item = {
					info: roleText + arr[1], //文字
					href: '#',
					close: false, //显示关闭按钮 
					speed: _barrage.speed || '12', //延迟,单位秒,默认12 
					color: arr[0] || '#ffffff', //颜色,默认黑色 
					old_ie_color: _barrage.color || '#ffffff', //ie低版兼容色,不能与网页背景相同,默认黑色
					font: _barrage.font || '40',
					opacity: _barrage.opacity || '1',
					area: _barrage.area || 'all'
				}
				$('body').barrager(item);
			}
		} else {
			$.fn.barrager.removeAll();
		}
	}
}

/**
 * 显示动画消息
 */
function showAnimationMsgItem(msg) {
	//暂时用gif实现简单的动画
	showMsgItem(msg);
}


function initCustomMessageCount() {
	//更新自定义消息计数
	var customMessageCount = LMC.getCustomMessageCount();
	if (customMessageCount && customMessageCount.length) {
		var likeCount = 0;
		for (var i in customMessageCount) {
			var countItem = customMessageCount[i];
			var _count = countItem.count;
			if (!_count || isNaN(_count)) {
				continue;
			}
			var _id = countItem._id;
			if (!_id) {
				continue;
			}
			var _customType = _id.customType;
			var _subGroupId = _id.subGroupId;
			if (_customType == 'like' && LMC.isSameGroup(_subGroupId)) {
				likeCount += _count;
			}
		}
		if (likeCount) {
			$('.like-count').attr('like-count', likeCount);
			$('.like-count').text(likeCount);
		}
	}
}

/**
 * 添加用户
 */
function addLoginUser(user) {
	var role = user.role;
	if (role == 'teacher' || role == 'zj') {
		return;
	}
	var $template = null;
	if (user.self) {
		$template = $('#chat-user-self');
	} else {
		$template = $('#chat-user-template').clone();
		$template.attr('id', 'data-user-' + user.userId);
	}

	var uname = user.self ? ('[我]' + user.nickname) : (user.nickname ? user.nickname : '匿名用户' + user.userId * 2);
	$template.find('.header-img').attr('src', decodeURIComponent(user.headerUrl) || (imagePath + '/placeholder/user_portrait_none.png'));
	/*    $template.find('.ranking').text('');
	    $template.find('.score').text(user.pointValue);*/
	$template.find('.user-name-box').text(uname);
	$template.attr('data-role', role);
	$template.attr('data-user-id', user.userId);
	$template.attr('data-point', user.pointValue);
	$template.find('.header-img').on('error', function() {
		var defaultImg = imagePath + '/placeholder/user_portrait_none.png';
		var src = $(this).attr('src');
		if (src != defaultImg) {
			$(this).attr('src', defaultImg);
		}
	});
	$('#users-list-box').append($template);
	$template.show();
}

function addBroadcastScore(duration) {
	sudokuStatus = 2;
	$('#music-btn').attr({
				'title': '您已经完成本次课前游戏啦',
				'data-toggle': 'tooltip',
				'data-placement': 'bottom'
			});
	$('#music-btn').tooltip();
	LMC.sendCustomMsg({
		"type": "sendGameNotice",
		'data': {
				"flag": 'sudoku',
				"content": {
					"nickname": nickname,
					"time": duration,
					"user_id": userId,
					"headerUrl": headerUrl,
					"group": subGroupId
				}
			}
	});
}
function addSudokuUser(user) {
	var time = mtimeToMsObject(user.time)
	var $template = null;
	$template = $('#chat-user-template').clone();
	$template.attr('id', 'data-user-' + user.user_id);
	if(user.user_id == userId) $template.addClass('self');
	$template.css('order',user.time);
	var uname = user.self ? ('[我]' + user.nickname) : (user.nickname ? user.nickname : '匿名用户' + user.userId * 2);
	$template.find('.header-img').attr('src',headerImg + decodeURIComponent(user.small_headImg) || (imagePath + '/placeholder/user_portrait_none.png'));
	/*    $template.find('.ranking').text('');
	    $template.find('.score').text(user.pointValue);*/
	$template.find('.user-name-box').text(uname);
	$template.attr('data-user-id', user.user_id);
	$template.find('.header-img').on('error', function() {
		var defaultImg = imagePath + '/placeholder/user_portrait_none.png';
		var src = $(this).attr('src');
		if (src != defaultImg) {
			$(this).attr('src', defaultImg);
		}
	});
	$template.find('.chat-user-score').text(time.minute + "'   " + time.second + '"');
	$('#users-list-box').append($template);
	$('#users-rank').append('<div class="chat-rank"></div>');
	$template.show();
}
/**
 * 遍历排序
 */
 function sortSudoku() {
 	$("#users-rank div.chat-rank").each(function(index,e){
 		$(e).text(index + 1);
 	})
 }
/**
 * 添加用户
 */
function flushUser(user) {
	var userId = user.userId;
	var $template = null;
	if (user.self) {
		$template = $('#chat-user-self');
	} else {
		$template = $('#data-user-' + userId);
	}
	$template.find('.header-img').attr('src', decodeURIComponent(user.headerUrl) || (imagePath + '/placeholder/user_portrait_none.png'));
	/*    $template.find('.ranking').text('');
	    $template.find('.score').text(user.pointValue);*/
	/*    $template.attr('data-point',user.pointValue);*/
	$template.show();
}

/**
 * 刷新用户排名
 */
function flushUserRank() {
	var $self = $('.chat-users .self');
	var $nextUsers = $self.nextAll('.chat-user');
	var arr = [];
	var pointHash = {};
	$nextUsers.each(function() {
		var $user = $(this);
		arr.push($user);
		var pointValue = $user.attr('data-point');
		if (!pointValue || isNaN(pointValue)) {
			pointValue = 0;
			$user.attr('data-point', pointValue);
		}
		pointHash[pointValue] = true;
	});

	var pointSelf = $self.attr('data-point');
	if (!pointSelf || isNaN(pointSelf)) {
		pointSelf = 0;
	}
	pointHash[pointSelf] = true;
	arr.sort(function(a, b) {
		var pointA = a.attr('data-point');
		var pointB = b.attr('data-point');
		return pointB - pointA;
	});

	var sortHash = {};
	var pointArr = [];
	for (var point in pointHash) {
		pointArr.push(point);
	}
	// 对分值进行排序
	pointArr.sort(function(a, b) {
		return b - a;
	});
	for (var sort in pointArr) {
		var sortPointValue = pointArr[sort];
		sortHash[sortPointValue] = (sort - (-1));
	}

	var sort = 1;
	while (arr.length > 0) {
		var $user = arr.pop();
		var sortPointValue = $user.attr('data-point');
		sort = sortHash[sortPointValue];
		$user.find('.ranking').text(sort > 99 ? ('') : sort);
		$user.insertAfter($self);
	}

	sort = sortHash[pointSelf];
	$self.find('.ranking').text(sort > 99 ? ('99+') : sort);


	var userPointCount = LMC.getUserPointCount();
	var targetPointArr = [];
	if (userPointCount && userPointCount.length) {
		var groupPointArr = [];
		for (var i in userPointCount) {
			var _userPoint = userPointCount[i] || {};
			var count = _userPoint.count;
			var totalPoint = _userPoint.totalPoint;
			var _id = _userPoint._id;
			if (!_userPoint || !_id || _id == 'ALL' || !count || !totalPoint) {
				continue;
			}
			_userPoint.avg = Math.floor(totalPoint / count);
			targetPointArr.push(_userPoint);
		}
	}

	if (targetPointArr.length) {
		// 目标积分数组
		targetPointArr.sort(function(a, b) {
			var avgPointA = a.avg;
			var avgPointB = b.avg;
			return avgPointB - avgPointA;
		});
		for (var i in targetPointArr) {
			var _userPoint = targetPointArr[i];
			if (LMC.isSameGroup(_userPoint._id)) {
				$('.my-class-rank').text(i - (-1));
				break;
			}
		}
	}
}

/**
 * 刷新用户积分
 * @param msg
 * @returns {Boolean}
 */
function flushUserPoint(msg) {
	msg = msg || {};
	var _userId = msg.userData.userId;
	if (_userId == userId) {
		// 如果是自身发送的消息则无需处理
		return false;
	}
	var content = msg.msgData.content;
	if (!content || isNaN(content)) {
		return false;
	}
	var $user = $('#data-user-' + _userId);
	var $score = $user.find('.score');
	var scoreValue = $score.text();
	if (!scoreValue || isNaN(scoreValue)) {
		scoreValue = 0;
	}
	scoreValue = scoreValue - 0 + content;
	$user.attr('data-point', scoreValue);
	$score.text(scoreValue);
}


/**
 * 答题模态框计时器timeout参数
 */
var interactionModalInterval = 0;

var interarctionQuestionType = 0;
/**
 * 显示题目
 */
function showQuestion(id, content) {
	var contentData = LMC.tools.parseJson(content);
	if (interactionModalInterval) {
		clearTimeout(interactionModalInterval);
		interactionModalInterval = 0;
	}

	$('#interactionModal').modal('hide');

	var interactionId = id;

	var $parents = $('#question-' + id);

	var img = contentData.img;

	var $answerList = contentData.sequence;

	var interactionType = contentData.type;

	interarctionQuestionType = contentData.type;

	var getQuestion = function() {
		return interactionType;
	}
	$(".modal-body-img").children().remove();
	$(".answer-img").children().remove();
	$(".question-choose-text-list").children().remove();
	$('#interactionModal .answer-list').empty();
	$('#interactionModal .answer-content').empty();
	$('#interactionModal .modal-body').hide();
	$('#interactionModal .' + interactionType).show();
	$('#interactionModal').attr('data-type', interactionType);
	$("#interactionModal").attr("data-interaction-id", interactionId);
	if (1 == interactionType || 2 == interactionType) {
		if (2 == interactionType) $(".answer-PanDuan-type p").html("多选题");
		else $(".answer-PanDuan-type p").html("单选题");
		$('#interactionModal .content').html(contentData.content);
		if (img !== null && img.length !== 0) {
			$(img).each(function() {
				$('<img src="" style="max-width:180px;margin: 20px 0 0 10px;">').attr('src', questionImg + this.url).appendTo(".modal-body-img");
			})
		}
		$($answerList).each(function() {
			var $answer = $(this);
			var $item = $('<div class="row"></div>');
			$item.append('<label><input value="" data-type="interaction" type="radio" class="layout-change" name="answer" style="display:none;"><span class="answer-index"></span><span class="answer-content"></span></label>');
			$item.find('input').attr('value', this.sequence);
			$item.find('input').attr('id', 'sequence-' + this.sequence);
			if (2 == interactionType) $item.find('input').attr('type', 'checkbox');
			$item.find('.answer-index').html(this.sequence);
			$item.find('.answer-content').html('      ' + this.answer);
			$('#interactionModal .answer-list').append($item);
			var $list = $('<li><label class="question-label" for=""></label></li>');
			$list.find('label').html(this.sequence);
			$list.find('label').attr('for', 'sequence-' + this.sequence);
			$('.question-choose-text-list').append($list);
		});
		$('div.XuanZe').show();
	} else if (3 == interactionType) {
		/*$('#interactionModal input[name="answer"]').val('');*/
		$('#interactionModal #answer-input').val('');
		$('#interactionModal .answer-content').html(contentData.content);
		if (img !== null && img.length !== 0) {
			$(img).each(function() {
				$('<img src="" style="max-width:180px;margin: 20px 0 0 10px;">').attr('src', questionImg + this.url).appendTo(".answer-img");
			})
		}
		$('.question-choose-text-list').append('<input type="text" placeholder="" class="form-control" id="answer-input" name="tkanswer">');
		if (contentData.remark) {
			$('#answer-input').attr('placeholder', contentData.remark);
		} else $('#answer-input').attr('placeholder', '请输入答案');
		$('div.TianKong').show();
	} else {

	}

	var timer = contentData.timer;
	var time = Math.floor(timer * 60) * 1000;
	if (timer && !isNaN(timer) && timer > 0 && timer < 100) {
		var second = Math.floor(timer * 60) * 1000;
		$('#interactionModal').attr('data-time', time - second);
		$('#answer-timer').text(mtimeToMsString(second));
		interactionModalInterval = setInterval(function() {
			second -= 1000;
			$('#interactionModal').attr('data-time', time - second);
			if (second <= 0) {
				$('#interactionModal').modal('hide');
				clearInterval(interactionModalInterval);
			}
			$('#answer-timer').text(mtimeToMsString(second));
		}, 1000);
	} else {
		$('#answer-timer').text('');
	}

	$('#interactionModal').modal({
		'show': true,
		'backdrop': 'static',
		'keyboard': false
	});
	var mathId = document.getElementById("interactionModal");
	MathJax.Hub.Config({
		tex2jax: {
			inlineMath: [
				['$', '$'],
				["\\(", "\\)"]
			],
			displayMath: [
				['$$', '$$'],
				["\\[", "\\]"]
			]
		}
	});
	MathJax.Hub.Queue(["Typeset", MathJax.Hub, mathId]);
}
$('#interactionModal').on('click', '.close', function() {
	var $obj = serverObj;
	$obj['id'] = $('#interactionModal').attr('data-qType');
	$obj['isRight'] = -1;
	$obj['duration'] = $('#interactionModal').attr('data-time');
	$obj['studentAnswer'] = '';
	ajaxRequest($obj, function(data) {}, "/api/liveQuestion/updateLiveQuestionStudentAnswer", true);
});

//发送互动消息
$("#interaction-send-button").click(function() {
	var id = $("#interactionModal").attr("data-interaction-id");
	var qId = $('#interactionModal').attr('data-qType');
	var type = $('#interactionModal').attr('data-type');
	var answer = '';
	if (3 == type) {
		answer = $('#interactionModal input[name="tkanswer"]').val();
	} else if (1 == type) {
		answer = $('#interactionModal input[name="answer"]:checked').val();
	} else if (2 == type) {
		$('#interactionModal input[name="answer"]:checked').each(function() {
			if (!answer)
				answer = $(this).val();
			else answer += ',' + $(this).val();
		})
	}
	if (!answer) {
		showCustomAlert('请输入答案');
		return;
	}

	LMC.sendCustomMsg({
		'type': 'sendAnswer',
		'data': {
			'flag': id,
			'content': answer
		}
	});
	var $objData = serverObj;
	$objData['id'] = $('#interactionModal').attr('data-qType');
	$objData['duration'] = $('#interactionModal').attr('data-time');
	$objData['isRight'] = '';
	$objData['studentAnswer'] = answer;
	ajaxRequest($objData, function(data) {}, "/api/liveQuestion/updateLiveQuestionStudentAnswer", true);
	clearInterval(interactionModalInterval);
	$('div.XuanZe').hide();
	$('div.Tiankong').hide();
	$('#interactionModal').modal('hide');
});



/**
 * 小测初始化
 */
function postTestInit(data) {
	showPostQuestion(data.appenddata.aaPaper);
	var answerArray = serverObj;
	answerArray['paperId'] = data.appenddata.aaPaper.id;
	$("input[type='radio']").one('click', function() {
		var _answerArray = answerArray;
		_answerArray['simpleContent'] = $(this).val();
		_answerArray['questionId'] = $(this).attr("name");
		ajaxRequest(_answerArray, saveUserResponse, "/api/aa/saveUserResponse", true);
	})
}

function saveUserResponse() {}
//课后小测
function showPostQuestion(obj) {
	if (interactionModalInterval) {
		clearTimeout(interactionModalInterval);
		interactionModalInterval = 0;
	}
	$('#modal-post-test').modal('hide');
	$("#post-test-send-button").data("type", obj.type);
	$("#post-test-send-button").data("paperId", obj.id);
	$(".modal-answer-num").empty();
	$("#modal-middle").empty();
	$.each(obj.questionList, function(index) {
		$(".modal-answer-num").append('<li><a id="modal-answer-num-' + (index + 1) + '" href="#answer-num-' + (index + 1) + '">' + (index + 1) + '</a></li>');
		var $answerBody = $("<div class='modal-body'></div>");
		$answerBody.attr('id', "answer-num-" + (index + 1));
		if (1 == this.type) {
			var $answerContent = $("<div></div>");
			$answerContent.addClass("row content modal-body-xuanze-answer");
			$answerContent.html((index + 1) + "." + this.content);
			var $answerList = $("<div></div>");
			$answerList.addClass("row answer-list");
			var img = $(this.attachList).filter(function() {
				return this.classify == 1
			}) || null;
			if (!!img) {
				var $imgList = $("<div class='answer-img'></div>");
				$.each(img, function() {
					var $img = $("<img src='' style='max-width:180px;margin: 20px 0 0 10px;'/>");
					$img.attr("src", questionImg + this.url);
					$imgList.append($img);
				});
				$answerContent.append($imgList);
			}
			var list = this.answerList;
			var $holder = $('<div class="question-choose" style="margin-bottom:30px;"><span class="question-choose-text">请作答</span><ul class="question-option-choose-text-list" data-name="' + this.id + '"></ul></div>');
			$.each(list, function(index) {
				var _list = this;
				var $option = $('<li><label class="question-option-label" for=""></label></li>');
				var $item = $('<div class="row"></div>');
				$item.append('<label><input value="" data-type="interaction" type="radio" class="layout-option-change" id="' + _list.id + '"" name="' + _list.questionId + '" style="display:none;"><span class="answer-index"></span><span class="answer-content"></span></label>');
				$item.find('input').attr('value', _list.sequence);
				$item.find('.answer-index').html(_list.sequence);
				$item.find('.answer-content').html(_list.content);
				$answerList.append($item);
				$option.find('label').attr('for', _list.id);
				$option.find('label').html(_list.sequence);
				$holder.find('.question-option-choose-text-list').append($option);
			});
			$answerBody.append($answerContent).append($answerList).append($holder);

			if (!!this.myAnswer) {
				$answerList.find("input[value ='" + this.myAnswer + "']").attr("checked", "checked");
				var id = $answerList.find("input[value ='" + this.myAnswer + "']").attr('id');
				$answerBody.find('.question-option-label[for ="' + id + '"]').addClass('question-label-choose');
			}
			$("#modal-middle").append($answerBody);
		}
	});
	var timer = obj.duration;
	if (timer <= 0) $("#post-test-send-button").click();
	if (timer && !isNaN(timer) && timer > 0) {
		var second = Math.floor(timer) * 1000;
		$('#answer-post-timer').text(mtimeToMsString(second));
		interactionModalInterval = setInterval(function() {
			second -= 1000;
			if (second <= 0) {
				$('#modal-post-test').modal('hide');
			}
			$('#answer-post-timer').text(mtimeToMsString(second));
		}, 1000);
	} else {
		$('#answer-post-timer').text('');
	}
	$('#modal-post-test').modal({
		'show': true,
		'backdrop': 'static',
		'keyboard': false
	});
	var mathId = document.getElementById("modal-post-test");
	MathJax.Hub.Config({
		tex2jax: {
			inlineMath: [
				['$', '$'],
				["\\(", "\\)"]
			],
			displayMath: [
				['$$', '$$'],
				["\\[", "\\]"]
			]
		}
	});
	MathJax.Hub.Queue(["Typeset", MathJax.Hub, mathId]);
}


/**
 *答案
 **/
function showCheckAnswer(obj) {
	$('#modal-check-answer').modal('hide');
	$('.modal-score .modal-score-self').html("得分：" + obj.answerScore.result);
	$('.modal-score .modal-score-full').html("(满分：" + obj.answerScore.sumF + "分)");
	$(".modal-answer-num").empty();
	$("#modal-check-answer-middle").empty();
	$.each(obj.aaPaper.questionList, function(index) {
		$(".modal-answer-num").append('<li><a href="#check-answer-' + (index + 1) + '" id="check-turn-' + (index + 1) + '">' + (index + 1) + '</a></li>');
		var $answerBody = $("<div class='modal-body'></div>");
		$answerBody.attr('id', "check-answer-" + (index + 1));
		if (1 == this.type) {
			var $answerContent = $("<div></div>");
			$answerContent.addClass("row content modal-body-xuanze-answer");
			$answerContent.html((index + 1) + "." + this.content);
			var $answerList = $("<div></div>");
			$answerList.addClass("row answer-list");
			var $answerImg = $(this.attachList).filter(function() {
				return this.classify == 1;
			}) || null;
			if (!!$answerImg) {
				var $imgList = $("<div class='answer-img'></div>");
				$.each($answerImg, function() {
					var $img = $("<img style='max-width:180px;margin: 20px 0 0 10px;'/>");
					$img.attr("src", questionImg + this.url);
					$imgList.append($img);
				});
				$answerContent.append($imgList);
			}
			var list = this.answerList;
			$.each(list, function(index) {
				var _list = this;
				var $item = $("<div class='row'></div>");
				$item.append('<span class="answer-index"></span><span class="answer-content"></span></label>');
				$item.find('.answer-index').html(_list.sequence);
				$item.find('.answer-content').html(_list.content);
				$answerList.append($item);
			});
			var $answer = $("<div class='answer'></div>");
			$answer.append('<span class="your-answer"></span><span class="real-answer"></span><span class="answer-img bg_answer"></span>');
			if (!!this.myAnswer) {
				$answer.find('.your-answer').html("我的答案:<span>" + this.myAnswer + "</span>");
				if (this.myAnswer == this.rightanswer) {
					$answer.find('.your-answer').find("span").addClass("modal-answer-green");
					$answer.find(".answer-img").addClass("modal-img-correct");
					$("#modal-check-answer #check-turn-" + (index + 1)).parent().addClass("modal-correct");
				} else {
					$answer.find('.your-answer').find("span").addClass("modal-answer-red");
					$answer.find(".answer-img").addClass("modal-img-error");
					$("#modal-check-answer #check-turn-" + (index + 1)).parent().addClass("modal-error");
				}
			} else {
				$answer.find('.your-answer').html("我的答案:");
				$answer.find(".answer-img").addClass("modal-img-error");
				$("#modal-check-answer #check-turn-" + (index + 1)).parent().addClass("modal-error");
			}
			$answer.find('.real-answer').html("正确答案:<span class='modal-answer-green'>" + this.rightanswer + "</span>");

			var $analysis = $("<div class='analysis'></div>");
			var $analysisImg = $(this.attachList).filter(function() {
				return this.classify == 2;
			}) || null;
			if (!!$analysisImg) {
				var $analysisImgList = $("<div class='analysis-img'></div>");
				$.each($analysisImg, function() {
					var $aImg = $("<img style='max-width:180px;margin: 20px 0 0 10px;'/>");
					$aImg.attr("src", questionImg + this.url);
					$analysisImgList.append($aImg);
				});
			}
			$analysis.append("<p class='analysis-title'>解析</p>");
			$analysis.append("<p class='analysis-content'></p>");
			$analysis.append($analysisImgList);
			$analysis.find(".analysis-content").html(this.analysis);
			$analysis.find(".analysis-content").html(this.analysis);
			$answerBody.append($answerContent).append($answerList).append($answer).append($analysis);
			$("#modal-check-answer-middle").append($answerBody);
		}
	});
	$('#modal-check-answer').modal({
		'show': true,
		'backdrop': 'static',
		'keyboard': false
	});
	var mathId = document.getElementById("modal-check-answer");
	MathJax.Hub.Config({
		tex2jax: {
			inlineMath: [
				['$', '$'],
				["\\(", "\\)"]
			],
			displayMath: [
				['$$', '$$'],
				["\\[", "\\]"]
			]
		}
	});
	MathJax.Hub.Queue(["Typeset", MathJax.Hub, mathId]);
}

/**
 * 
 */
function showPointRedPacket(msg) {
	var title = '收到红包';
	if ('initCompleted' == msg.type) {
		title = '成功登陆';
	} else if ('like' == msg.type) {
		title = '给老师点赞';
	} else if ('flower' == msg.type) {
		title = '送花';
	} else if ('sendAnswer' == msg.type) {
		if (msg.complexMatch) {
			title = '回答正确';
		} else {
			title = '回答错误';
		}
	} else if ('points' == msg.type) {
		title = '收到积分红包';
	}

	showRedPacket(msg.pointValue, title);

	// 发送积分通知让其他同学同步当前学员的积分
	LMC.sendCustomMsg({
		'type': 'sendPointNotify',
		'data': {
			'content': msg.pointValue
		}
	});
}


/*
 *数独框
 */
function closeSudoku() {
	$('.pop-start').hide();
}
function openSudoku() {
	$('.pop-start').hide();
	createSudokuIframe();
}
function createSudokuIframe() {
	var sudoku = $(sudokuIframe).clone();
	var frame = sudoku.attr('class','sudoku-div').append(sudoku);
	$('#window').append(frame);
}
$('.pop-start-button-close').click(function() {
	openSudoku();
})
function closeSudokuIframe() {
	$('.sudoku-div').remove();
}
/**
 * 显示评论对话框
 */
function showComment() {
	$('#commentModal').modal({
		'show': true
	});
}

/**
 * 显示吐槽框
 **/
function showDisclose() {
	ajaxRequest(serverObj, discloseCheck, "/api/spitslot/getSpitslotCount");

	function discloseCheck(data) {
		if (data.resulttype == 1) {
			$('#discloseModal').modal({
				'show': true
			});
		} else showCustomAlert("吐槽次数过多，请稍后再吐槽！");
	}
}

/**
 *  点击表情框
 **/
function selectEmotionImg(selImg) {
	if ($(selImg).attr('id').length > $('#text_msg_num').html()) {

	} else {
		var $textMsgInput = $('#send_msg_text');
		$textMsgInput.val($textMsgInput.val() + selImg.id);
		$("#text_msg_num").html(50 - $("#send_msg_text").val().length);
	}
	$("#send_msg_text").focus();
}

//私聊选中表情
function selectEmotionImg1(selImg) {
	var textMsgInput = '.ft-row';
	$(textMsgInput).val($(textMsgInput).val() + selImg.id);
	if ($("#chatContent").val().length > 0) $('.ptc-foot .ft-submit').css('backgroundColor', '#685a86');
	else $('.ptc-foot .ft-submit').css('backgroundColor', '#d7d7d7');
	$(textMsgInput).focus();
}
/**
 * 展示扩展数据
 * @param datas
 */
function showExtDataListInit(datas) {
	if (!datas || !datas.length) {
		return false;
	}
	for (var i in datas) {
		var data = datas[i];
		var type = data.type;
		var value = data.value;
		if (!value) {
			continue;
		}

		var dataId = data.id;
		if (type == 'question') {
			var questionData = LMC.tools.parseJson(value);
			if (!questionData) {
				continue;
			}
			var questionType = questionData.type;
			if (!questionType) {
				continue;
			}
			var $question = null;

			$question = $('#qustion-item-template').clone();
			$question.removeAttr('id');
			var $questionContent = $question.find('.question-content');
			$questionContent.html(questionData.trunk);
			var $questionList = $question.find('.question-list');
			$questionList.attr('id', 'question-' + dataId);
			$questionList.attr('data-id', dataId);

			if (questionType == 'XuanZe' || questionType == 'PanDuan' || questionType == 'DuoXuan') {
				var $answerList = $question.find('.answer-list');
				for (var i in questionData.answer) {
					var answer = questionData.answer[i];
					var $answerItem = $('<div class="answer-item" data-index=""></div>');
					$answerItem.attr('data-index', answer.index);
					$answerItem.html(answer.value);
					$answerList.append($answerItem);
				}
			}
			if (!$question) {
				continue;
			}
			$('#question-list-box').append($question);
			$question.show();
		}
	};

	//加载mathjax
	LMC.tools.loadScript('http://cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML', function() {
		MathJax.Hub.Config({
			tex2jax: {
				inlineMath: [
					['$', '$'],
					['\\(', '\\)']
				]
			}
		});
	}, true);
}
//发送互动消息
$("#comment-send-button").click(function() {
	contentValue = $("#comment-content-value").val() / 2 || "";
	teacherValue = $("#comment-teacher-value").val() / 2 || "";
	degreeValue = $("#comment-degree-value").val();
	if (contentValue && teacherValue && degreeValue) {
		var commentObj = serverObj;
		commentObj["courseContentEval"] = contentValue / 2;
		commentObj["teacherEvaluation"] = teacherValue / 2;
		commentObj["courseDifficulty"] = degreeValue;
		commentObj["content"] = $("#comment-text").val();
	} else if (contentValue == '') {
		showCustomAlert("请评价课程内容");
		return;
	} else if (teacherValue == '') {
		showCustomAlert("请评价授课老师");
		return;
	} else if (degreeValue == '') {
		showCustomAlert("请评价本节课难度");
		return;
	}
	$('#commentModal').modal('hide');
});


LMC.init({
	'appConfig': { // 应用配置
		'lmcServer': lmcServer || 'http://lmc.91haoke.com/core',
		'cacheJs': true, // 是否缓存JavaScript文件,默认不缓存
		'appId': appId, // 应用id
		'appSign': appSign, // 应用授权签名,
		'expire': expire, //鉴权到期时间
		'random': random, //鉴权随机字符串
		'debug': true, //是否输出调试信息
		'errorPage': null, // 加载错误页面,
		'repeatPage': null, // 重复登录错误页面,
		'timeoutPage': null, // 鉴权超时错误页面
		'volume': 80, // 默认音量
	},
	'liveConfig': { // 直播配置
		'roomId': roomId // 直播间id
	},
	'userConfig': { // 用户配置
		'userId': userId, // 用户身份标识
		'nickname': nickname, // 用户身份标识
		'headerUrl': headerUrl, // 用户头像路径
		'role': role, // ['teacher','assistant','student']  用户权限，可以自行扩展
		'subGroupId': subGroupId, //用户分组id,如果所属多个分则用逗号分隔,如果属于全部组则subGroupId为ALL
		'onlyGroupMsg': true, //设置用户是否只显示组内消息
	},
	'modules': { //模块配置
		'notify': { //回调通知模块
			'onInitCompleted': function(self) {
				//更新自定义消息计数
				initCustomMessageCount();
				/*// 更新用户积分排名
				flushUserRank();
				// 启动定时任务刷新积分排名,没30秒刷新一次
				setInterval(flushUserRank, 30 * 1000);*/
				initEmoji();
				initEmojiPrivate();
				initModal();
				LMC.setUseBarrage($('#barrage_input').is(':checked'));
				var base = LMC.getBase();
				var tempTime = new Date();
				liveStartTime =base.startTime;
				if(tempTime.getTime() < liveStartTime) signSuduku();
					else {
						$('#music-btn').attr({
							'title': '课前数独游戏仅在直播课前1小时内开放哦',
							'data-toggle': 'tooltip',
							'data-placement': 'bottom'
						});
						$('#music-btn').tooltip();
					}
				if (replay == 'true') {
					$('.openChat').hide();
					ajaxRequest(serverObj, function(data) {
						if(data.appenddata != null && data.appenddata.length != 0) {
							$('.answer-item-icons').show();
							var ww = new answerItem(data.appenddata);
						}
					}, "/api/liveQuestion/getPushQuestionList",true);
				}
				/*if(serverObj.coursePaperId == '') {
						 bgImg = 'image/placeholder/player_bg_end.png';
					} else {
						 bgImg = 'image/placeholder/player_bg_end_test.png';
					}*/
				/*$('#time-marker').html(convertMillisecondToTimeHtml(base.startTime) + '~' + convertMillisecondToTimeHtml(base.endTime));*/
				$('#live-name').text(base.liveName);
				$('#live-name').attr("title", base.liveName);
			},
			'onUserJoin': function(user) {
				/*addLoginUser(user);*/
			},
			'onUserChange': function(user) {
				/*flushUser(user);*/
			},
			'onGetPoint': function(msg) {
				showPointRedPacket(msg);
			},
			'onPollingTrigger': function(status) {
				systemTime = status.serverTime;
				var liveStatus = status.liveStatus;
				if ('start' == liveStatus) {
					playerStatus = 2;
					/*$("#timmer").text('直播中:' +  mtimeToHMsString((status.serverTime - status.liveStartTime)));*/
					var bgImg = 'image/placeholder/player_bg_start.png';
					$('#mianPlayerBox').css({
						'background': 'url("' + bgImg + '") no-repeat center center',
						'backgroundColor': '#110f16'
					});
					/*if(sendStatus == 0) {
		                    var _serverObjStatus = serverObj;
		                    _serverObjStatus['studentId'] = userId;
		                    _serverObjStatus['status'] = 2;
		                    ajaxRequest(_serverObjStatus,function (){},'/api/courseUserStatus/addCourseUserStatus');
		                    sendStatus = 1;
	 	               }*/
				} else if ('suspend' == liveStatus) {
					playerStatus = 3;
					/*					$('#timmer').text('课间休息');*/
					var bgImg = 'image/placeholder/player_bg_suspend.png';
					$('#mianPlayerBox').css({
						'background': 'url("' + bgImg + '") no-repeat center center',
						'backgroundColor': '#110f16'
					});
					/*if(sendStatus == 0) {
		                    var _serverObjStatus = serverObj;
		                    _serverObjStatus['studentId'] = userId;
		                    _serverObjStatus['status'] = 2;
		                    ajaxRequest(_serverObjStatus,function (){},'/api/courseUserStatus/addCourseUserStatus');
		                    sendStatus = 1;
	 	               }*/
				} else if ('end' == liveStatus) {
					playerStatus = 4;
					/*					$('#timmer').text('已下课');*/
					if (serverObj.coursePaperId == '') {
						var bgImg = 'image/placeholder/player_bg_end.png';
						$('#mianPlayerBox').css({
							'background': 'url("' + bgImg + '") no-repeat center center',
							'backgroundColor': '#110f16'
						});
					} else {
						var bgImg = 'image/placeholder/player_bg_end_test.png';
						$('#mianPlayerBox').css({
							'background': 'url("' + bgImg + '") no-repeat center center',
							'backgroundColor': '#110f16'
						});
					}

				} else {
					/*					$('未开始');*/
					playerStatus = 1;
					var bgImg = 'image/placeholder/player_bg_wait.png';
					$('#mianPlayerBox').css({
						'background': 'url("' + bgImg + '") no-repeat center center',
						'backgroundColor': '#110f16'
					});
					/*if(sendStatus == 0) {
		                    var _serverObjStatus = serverObj;
		                    _serverObjStatus['studentId'] = userId;
		                    _serverObjStatus['status'] = 1;
		                    ajaxRequest(_serverObjStatus,function (){},'/api/courseUserStatus/addCourseUserStatus');
		                    sendStatus = 1;
	 	               }*/
				}
				if (oneEvent == 0) {
					_time = status.serverTime;
					if(realStartTime != undefined) realStartTime = status.realStartTime;
					var questionStatus = '';
					var _serverObjStatus = serverObj;
					if (playerStatus == 1) {
						_serverObjStatus['status'] = 1;
					} else if (playerStatus !== 1 && playerStatus !== 4) {
						_serverObjStatus['status'] = 2;
					}
					if(playerStatus != 1) {
					}
					ajaxRequest(_serverObjStatus, function() {}, "/api/courseUserStatus/addCourseUserStatus");
					//判断是否有小测
					if (serverObj.coursePaperId) {
						$("li.title-right-test").hover(function() {
							if (systemTime > classEndTime) {
								$(".title-right-test").attr('title', '');
								$(".title-right-test").addClass("title-right-test-open");
								$(".title-right-test").click(function() {
									var _test = serverObj;
									_test['type'] = 2;
									ajaxRequest(_test, postJudge, "/api/aa/getPaperStatus");

									function postJudge(data) {
										if (data.resulttype == 1) {
											$("#judgeModal").modal({
												'show': true,
												'backdrop': 'static',
												'keyboard': false
											});
										} else if (data.resulttype == -2) alert("本节没有小测");
										else if (data.resulttype == 2) {
											ajaxRequest(serverObj, myPaper, "/api/aa/myPaper");

											function myPaper(data) {
												$('#modal-post-test').modal('hide');
												showCheckAnswer(data.appenddata);
											}
										} else if (data.resulttype == 0) {
											ajaxRequest(serverObj, myPaper, "/api/aa/myPaper");

											function myPaper(data) {
												$('#modal-post-test').modal('hide');
												showCheckAnswer(data.appenddata);
											}
										}
									}
								});
								$('li.title-right-test').off('mouseenter').unbind('mouseleave');
							}
						}, function() {});
					}
					oneEvent = 1;
				}

				if (status.speaking == 'off') {
					$('#speaking').val('禁言中');
					$('#send_msg_text').attr("readonly", "readonly");
					$('#send_msg_text').val();
					$('#send_msg_text').attr("placeholder", "禁言中");
				} else {
					$('#speaking').val('');
					$('#send_msg_text').attr("readonly", false);
					$('#send_msg_text').val();
					$('#send_msg_text').attr("placeholder", "");
				}
				if (status.barrage == 'on') {
					$('#barrage').show();
					$('#setting').show();

				} else {
					$.fn.barrager.removeAll();
					$('#barrage').hide();
					$('#setting').hide();
					$('#card-barrage-setting').hide();

				}
				barrage = status.barrage;
			},
			'onImCustomArrive': function(msg) { //当自定义消息到达时回调
				LMC.debugLog('onImCustomArrive');
				LMC.debugLog(msg);
				msg = msg || {};
				var type = msg.type;
				var msgData = msg.data || {};
				var status = msg.status || '';
				switch (type) {
					case 'flower': //送花
						showAnimationMsgItem({
							'imgTime': msgData.msgData.time,
							'fromAccount': msgData.userData.userId,
							'headerUrl': msgData.userData.headerUrl,
							'fromAccountNick': msgData.userData.nickname,
							'role': msgData.userData.role,
							'content': '<img src="' + imagePath + '/library/flower.png"/>',
							'icon': true
						});
						break;
					case 'like': //点赞
						showAnimationMsgItem({
							'imgTime': msgData.time,
							'fromAccount': msgData.userData.userId,
							'headerUrl': msgData.userData.headerUrl,
							'fromAccountNick': msgData.userData.nickname,
							'role': msgData.userData.role,
							'content': '<img src="' + imagePath + '/library/good.png"/>',
							'icon': true
						});

						var likeCount = $('.like-count').attr('like-count') || 0;
						likeCount++;
						$('.like-count').attr('like-count', likeCount);
						$('.like-count').text(likeCount);
						break;
					case 'barrage': //弹幕,弹幕是系统内置自动定义消息
						showBarrageItem({
							'fromAccount': msgData.userData.userId,
							'headerUrl': msgData.userData.headerUrl,
							'fromAccountNick': msgData.userData.nickname,
							'role': msgData.userData.role,
							'content': msgData.msgData.content
						});
						break;
					case 'gift': //礼物
						break;
					case 'sendQuestion':
						var delay = 0;
						if (LMC.tools.isMobile()) {
							// 移动端延迟10秒
							delay = 10 * 1000;
						} else {
							// 非移动端延迟4.5秒
							delay = 4.5 * 1000;
						}
						setTimeout(function() {
							showQuestion(msgData.msgData.flag, msgData.msgData.content);
						}, delay);
						var $obj = serverObj;
						$obj['liveQuestionId'] = msgData.msgData.flag;
						$obj['studentAnswer'] = '';
						$obj['duration'] = '';
						$obj['isRight'] = -2;
						ajaxRequest($obj, function(data) {
							$('#interactionModal').attr('data-qType', data.appenddata.id);
						}, "/api/liveQuestion/addLiveQuestionStudentAnswer", true);
						break;
					case 'closeQuestion':
						$('#interactionModal').modal('hide');
						break;
					case 'sendPointNotify':
						flushUserPoint(msgData);
						break;
					case 'sendAnswer':
						break;
					case 'privateChat': //私聊消息
						showPrivateMsg(msgData);
						$('.ptc-content').scrollTop($('.ptc-content')[0].scrollHeight);
						break;
					case 'sendGameNotice': //发送游戏通知
						switch (msgData.msgData.flag) {
							case 'sudoku':
								if(msgData.msgData.content.group == subGroupId) {
									addSudokuUser(msgData.msgData.content);
									sortSudoku();
								}
								break;
						}
						break;
					default:
						break;
				}

			},
			'onCommandArrive': function(msg) { // 当命令消息到达时回调
				msg = msg || {};
				var type = msg.type;
				var msgData = msg.data || {};
				var status = msg.status || '';
				if ('success' == status && msgData.resposeParam.status == 'end') {
					showComment();
				}
				LMC.debugLog(msg);
			},
			'onUserStatusChange': function(msg) { //当用户状态变化时回调
				if (!msg) {
					return false;
				}
				LMC.debugLog(msg);

				var type = msg.type;
				var msgData = msg.data || {};
				var status = msg.status || '';
				switch (type) {
					case 'userLoginStatusNotify':
						switch (status) {
							case 'login': //处理用户登录成功,发送显示一条进入课堂消息
								//						var data =  {
								//							'fromAccount' : msgData.userData.userId,
								//							'headerUrl' : msgData.userData.headerUrl,
								//							'fromAccountNick': msgData.userData.nickname,
								//							'role' : msgData.userData.role,
								//							'content': '进入课堂'
								//						}
								//						showMsgItem(data);
								break;
							case 'repeat': //处理用户重复登录
								break;
							case 'fial': //处理用户登录错误
								alert('登录失败,请刷新重试!');
								break;
							default:
								break;
						}
						break;
					case '': //未知的消息类型
						break;
					default:
						break;
				}
			},
			'onMediaPlayerStatusChange': null, //当媒体播放器状态变化时回调
			'onLiveStatusChange': function(msg) { //当直播状态变化时回调
				msg = msg || {};
				if (msg.status == 'start') {
					$('#music-btn').attr({
						'title': '课前数独游戏仅在直播课前1小时内开放哦',
						'data-toggle': 'tooltip',
						'data-placement': 'bottom'
					});
					$('#music-btn').tooltip();
				}
			},
			'onTextMsgSend': function(msg) { //当发送普通消息时回调
				LMC.debugLog('onTextMsgSend');
				LMC.debugLog(msg);
			},
			'onCustomMsgSend': function(msg) { //当im发送自定义信息完成时回调
				LMC.debugLog('onCustomMsgSend');
				LMC.debugLog(msg);
			},
			'onCustomMsgRejected': function(msg) { //当发送自定义消息被拒绝时回调
				if (msg.error == 'undefined') {
					showAlert('未知消息');
				} else if (msg.error == 'not_allow') {
					showAlert('没有权限执行该操作');
				} else if (msg.error == 'too_fast') {
					var lastTime = msg.lastTime;
					var interval = msg.interval;
					var time = msg.time;
					var countDwon = Math.ceil(((lastTime + interval * 1000) - time) / 1000) || 1;
					if (msg.msg.type == 'flower') {
						showAlert('你刚刚送过花了!下一朵花要等到' + countDwon + '秒后啦!');
					} else if (msg.msg.type == 'like') {
						showAlert('你刚刚点过赞了!下一个赞等到' + countDwon + '秒后啦!');
					} else {
						showAlert('操作太快,请再等一会吧');
					}
				} else if (msg.error == 'too_much') {
					if (msg.msg.type == 'like') {
						showAlert('你已经点赞啦');
					} else {
						showAlert('不可重复操作');
					}
				}
			},
			'onCommandSend': function(msg) { // 当发送命令消息时回调
				LMC.debugLog('onCommandSend');
				LMC.debugLog(msg);
			},
			'onError': function(msg) { // 当发生错误或者异常时回调
				msg = msg || {};
				if (msg.type == 'sendTextMsgError') {
					showAlert(msg.errInfo || '发送消息错误');
				}
			},
			'onOrientationChange': function(orientation) { //当屏幕方向改变时触发,在初始化时会触发
				if (isMobile()) {
					//重新计算窗口宽高
					setTimeout(function() {
						var windowHeight = $(window).height();
						var chatBoxHeight = 0;
						var playerBoxHeight = 0;
						var headdingHeight = 40;
						if (orientation == 'horizontal') {
							playerBoxHeight = windowHeight - headdingHeight;
							chatBoxHeight = playerBoxHeight;
							$('body').removeClass('vertical');
						} else if (orientation == 'vertical') {
							playerBoxHeight = Math.floor(windowHeight * 0.40) - headdingHeight;
							chatBoxHeight = windowHeight - playerBoxHeight - headdingHeight;
							$('body').removeClass('horizontal');
						}
						if (playerBoxHeight) {
							$('.player-box').css({
								'height': playerBoxHeight
							});
						}
						if (chatBoxHeight) {
							$('.chat-box').css({
								'height': chatBoxHeight
							});
						}
					}, 350);
				}

				$('body').addClass(orientation);
			},
			'onAudioPlayerStatuChange': function(msg) {
				//背景音乐
				msg = msg || {};
				/*if (msg.status == 'play') {
					$('.title-right-music-img').addClass('circle-active');
					$('.title-right-music-img-rod').addClass('circle-active-rod');
					$('#music-btn span').addClass("white");
				} else {
					$('.title-right-music-img').removeClass('circle-active');
					$('.title-right-music-img-rod').removeClass('circle-active-rod');
					$('#music-btn span').removeClass("white");
					$('#music-btn').hover(function() {
						$('#music-btn').css("color", "#fff");
					}, function() {
						$('#music-btn').css("color", "#685a86");
					});
				}*/
			},
			'onExtDataListInit': function(datas) {
				showExtDataListInit(datas);
			},
			'onNetworkError': function(msg) {

			}
		},
		'player': { //播放器模块
			'mianPlayerBox': 'mianPlayerBox', //主播放器容器id(主播放器用于播放推流视频和推流白板)
			'mianPlayerBoxBackground': { // 主播放器背景填充
				'wait': 'image/placeholder/1e1b24.png',
				'live': 'image/placeholder/1e1b24.png',
				'suspend': 'image/placeholder/1e1b24.png',
				'end': 'image/placeholder/1e1b24.png'
			},
			'auxPlayerBox': 'auxPlayerBox', //辅助放器容器id(辅助播放器用于播放广告,摄像头等)
			'audioPlayerBox': 'audioPlayerBox' //主播放器容器id(音频播放器用于播放一般声音,暖场音频等)

		},
		'im': { //即时通信模块
			'onlyGroupMsg': true, //是否只显示本组消息
			'emojiBtn': 'emojiBtn1', // 弹出emoji包的按钮
			'voiceBtn': 'voiceBtn', // 弹出语音功能的按钮
			'textMsgSendBtn': 'text_msg_send_btn', // 文本消息发送按钮
			'textMsgInput': 'send_msg_text', // 文本消息发送按钮
			'emojis': { // emoji表情符号
				'append': false, //默认是true,
				'emojiTextTemplate' : '[${content}]',
				'emojiImgBox': 'emoji-img-box', //表情包图片容器
				'imgs': {
					"微笑": "image/emojis/smile.png",
					"可爱": "image/emojis/blush.png",
					"呲牙": "image/emojis/grin.png",
					"喜欢": "image/emojis/heart_eyes.png",
					"吐舌头": "image/emojis/stuck_out_tongue_closed_eyes.png",
					"调皮": "image/emojis/stuck_out_tongue_winking_eye.png",
					"激动": "image/emojis/joy.png",
					"不屑": "image/emojis/unamused.png",
					"哼": "image/emojis/smirk.png",
					"酷": "image/emojis/sunglasses.png",
					"呆": "image/emojis/neutral_face.png",
					"飞吻": "image/emojis/kissing_heart.png",
					"生气": "image/emojis/angry.png",
					"闪瞎": "image/emojis/astonished.png",
					"瞪眼": "image/emojis/flushed.png",
					"难受": "image/emojis/pensive.png",
					"愤怒": "image/emojis/rage.png",
					"纠结": "image/emojis/confounded.png",
					"怒": "image/emojis/triumph.png",
					"困": "image/emojis/sleeping.png",
					"吃惊": "image/emojis/fearful.png",
					"汗": "image/emojis/sweat.png",
					"惊恐": "image/emojis/scream.png",
					"大哭": "image/emojis/sob.png",
					"花": "image/emojis/rose.png",
					"西瓜": "image/emojis/watermelon.png",
					"一百分": "image/emojis/100.png",
					"厉害": "image/emojis/thumbsup.png",
					"ok": "image/emojis/ok_hand.png",
					"鼓掌": "image/emojis/clap.png",
					"胜利": "image/emojis/v.png",
					"祈祷": "image/emojis/pray.png",
					"不听": "image/emojis/hear_no_evil.png",
					"不说": "image/emojis/speak_no_evil.png",
					"不看": "image/emojis/see_no_evil.png",
					"魔性": "image/emojis/trollface.png"
				}
				// [{//表情图片数据'name' : 'DaXiao','url' : 'xxxxx.gif'} ]
			},
			'chatItemsBox': 'chatItemsBox', //聊天消息区容器
			'chatItemRender': function(msg) { //聊天内容渲染器,
				showMsgItem(msg);
			},
		}
	}

});

$('#send_msg_text').focus(function() {
	$('body').addClass('inputin');
});

$('#send_msg_text').blur(function() {
	$('body').removeClass('inputin');
});

$('#snedFlowerBtn').click(function() {
	if (LMC.getStatus().speaking == 'off') {
		showAlert('禁言中');
	} else {
		LMC.sendCustomMsg({
			'type': 'flower'
		});
	}
});

$('#snedLikeBtn,#topSnedLikeBtn').click(function() {
	if (LMC.getStatus().speaking == 'off') {
		showAlert('禁言中');
	} else {
		LMC.sendCustomMsg({
			'type': 'like'
		});
	}
});


$('#chat-items').on('mouseenter', function() {
	isOverMsg = true;
});

$('#chat-items').on('mouseleave', function() {
	isOverMsg = false;
});

$('#chat-items').on('touchstart', function() {
	isOverMsg = true;
});

$('#chat-items').on('touchend', function() {
	isOverMsg = false;
});


$('#music-btn').click(function() {
	if(sudokuStatus == 1 && systemTime < liveStartTime && $('.sudoku-div').length == 0) {
		$('.pop-start').show();
	}
});

$(".title-right-disclose").click(function() {
	showDisclose();
});
/* 弹幕设置 */

isClickSettingBox = false;
isClickSettingBtn = false;

//点击其他区域是表情包消失
$(window).click(function() {
	if (isClickSettingBtn) {
		var temp = $('#card-barrage-setting').is(':hidden');
		if (temp) {
			$("#card-barrage-setting").show();
			isClickSettingBtn = false;
			return;
		} else {
			$("#card-barrage-setting").hide();
			isClickSettingBtn = false;
			return;
		}
	}
	if (!isClickSettingBox) {
		$("#card-barrage-setting").hide();
	}
	isClickSettingBox = false;
});

$("#card-barrage-setting").click(function() {
	isClickSettingBox = true;
});
$("#setting-img").click(function() {
	isClickSettingBtn = true;
});
/* 弹幕属性颜色设置 */
$(".card-barrage-color-content ul li span").click(function() {
	if (!$(this).parent().css("card-barrage-color")) {
		_barrageColor = $(this).css("background-color");
		$(this).parent().addClass("card-barrage-color").siblings(".card-barrage-color").removeClass("card-barrage-color");
	}
})

$(".card-barrage-play-position-content li").click(function() {
		if (!$(this).hasClass($(this).data("active"))) {
			_barrage['area'] = $(this).data("area");
			$(this).addClass($(this).data("active")).siblings().removeClass("area-top-active area-all-active area-bottom-active");
		}
	})
	/* 弹幕属性设置 */
$('#ex1,#ex2,#ex3').slider({
	tooltip: 'hide'
});
//透明度
$("#ex1").on("slide", function(slideEvt) {
	$("#opacityText").text(slideEvt.value + "%");
});
//速度
$("#ex2").on("slide", function(slideEvt) {
	$("#speedText").text(slideEvt.value);
});
//字体大小
$("#ex3").on("slide", function(slideEvt) {
	$("#fontText").text(slideEvt.value);
});
$("#ex1").on("slideStop", function(slideEvt) {
	$("#opacityText").text(slideEvt.value + "%");
	_barrage['opacity'] = slideEvt.value / 100;
});
$("#ex2").on("slideStop", function(slideEvt) {
	$("#speedText").text(slideEvt.value);
	_barrage['speed'] = 26 - slideEvt.value;
});
$("#ex3").on("slideStop", function(slideEvt) {
	$("#fontText").text(slideEvt.value);
	_barrage['font'] = slideEvt.value;
});

/*聊天input*/
$("#text_msg_send_btn").click(function() {
	if (LMC.getStatus().speaking == 'off') {
		showAlert('禁言中');
	} else {
		if ($.trim($("#send_msg_text").val()) == '') {
			$("#send_msg_text").val('');
			showAlert('请输入内容');
			return;
		}
		LMC.sendTextMsg(_barrageColor + "/*/" + $('#send_msg_text').val());
		$('#send_msg_text').val('');
		$("#text_msg_num").html(50 - $("#send_msg_text").val().length);
	}
})
$("#send_msg_text").keypress(function(event) {
	e = event ? event : (window.event ? window.event : null);
	if (e.keyCode == 13 && !e.ctrlKey) {
		event.preventDefault();
		$("#text_msg_send_btn").click();
		$("#send_msg_text").focus();
	} else if (e.ctrlKey) {
		var value = $('#send_msg_text').val() + "\n";
		$('#send_msg_text').val(value);
	}
});

$("#text_msg_num").html(50 - $("#send_msg_text").val().length);
$("#send_msg_text").on('input propertychange', function() {
	$("#text_msg_num").html(50 - $("#send_msg_text").val().length);
});


/**
 * 功能初始化
 * 
 * @returns
 */
function init() {
	if (isMobile() && !isWeiXin()) {
		var windowHeight = $(window).height();
		var playerBoxHeight = $('.player-box').height();
		//		if(windowHeight && playerBoxHeight){
		//			if(Math.floor(playerBoxHeight / windowHeight * 100) != 34){
		//				$('body').addClass('correct');
		//			}
		//		}
	}
}

$('#barrage_input').change(function() {
		var $input = $(this);
		var useBarrage = $input.is(':checked');
		if (!useBarrage) {
			$.fn.barrager.removeAll();
			$("label.slide-checkbox").css({
				"left": "25px",
				"color": "#666"
			});
			$(".switch").css("background", "#999");
		} else {
			$("label.slide-checkbox").css({
				"left": "7px",
				"color": "#272331"
			});
			$(".switch").css("background", "#685a86");
		}
		LMC.setUseBarrage(useBarrage);
	});

/* 页面初始化 */
function initHtml() {
	ajaxRequest(serverObj, htmlInit, "/api/course/getKnowledge");
}
/* 弹出框高度初始化 */
function initModal() {
	var practice_h = window.screen.availHeight * 0.55 - 130;
	var test_h = window.screen.availHeight * 0.70 - 60;
	var chat_h = window.screen.availHeight * 0.15;
	if (practice_h < 360) {
		$('#interactionModal .modal-body').css('maxHeight', practice_h + 'px');
		$('#persistent .modal-body').css('maxHeight', practice_h + 'px');
	}
	if (test_h < 580) {
		$('.modal-scroll').css('maxHeight', test_h + 'px');
	}
	$('.ptc-content').css('minHeight', chat_h + 'px');
}
/* 初始化表情框 */
function initEmoji() {
	_emojibtn = true;
	$('#emoji-img-box').hide();
	var $emojiImgBox = $('#emoji-img-box');
	var emojis = LMC.getEmojis();
	for (var index in emojis) {
		var emotions = $('<img>').attr({
			'id': emojis[index][0],
			'src': emojis[index][1],
			'style': 'cursor:pointer;height:24px;'
		}).click(function() {
			selectEmotionImg(this);
			_emoji = true;
		});
		$('<li>').append(emotions).appendTo($emojiImgBox);
	}

	window.isClickEmojiImgBox = false;
	window.isClickEmojiBtn = false;

	$(window).click(function() {
		if (isClickEmojiBtn) {
			$('#emoji-img-box').show();
			isClickEmojiBtn = false;
			return;
		}
		$('#emoji-img-box').hide();

		isClickEmojiImgBox = false;
	});


	$('#emojiBtn').on('mousedown', function() {
		if (LMC.getStatus().speaking == 'off') {
			showAlert('禁言中');
		} else isClickEmojiBtn = true;
	});
}
/* 初始化私聊表情 */
function initEmojiPrivate() {
	_emojibtn = true;
	$('#emoji-img-box1').hide();
	var $emojiImgBox = $('#emoji-img-box1');
	var emojis = LMC.getEmojis();
	for (var index in emojis) {
		var emotions = $('<img>').attr({
			'id': emojis[index][0],
			'src': emojis[index][1],
			'style': 'cursor:pointer;'
		}).click(function() {
			selectEmotionImg1(this);
			_emoji = true;
		});
		$('<li>').append(emotions).appendTo($emojiImgBox);
	}

	window.isClickEmojiImgBox1 = false;
	window.isClickEmojiBtn1 = false;

	$(window).click(function() {
		if (isClickEmojiBtn1) {
			$('#emoji-img-box1').show();
			isClickEmojiBtn1 = false;
			return;
		}
		/*if (!isClickEmojiImgBox1) {
			$('#emoji-img-box1').hide();
		}*/
		$('#emoji-img-box1').hide();
		isClickEmojiImgBox1 = false;
	});

	$emojiImgBox.click(function() {
		isClickEmojiImgBox1 = true;
	});


	$('#emojiBtn1').on('mousedown', function() {
		isClickEmojiBtn1 = true;
	});
}


/* 初始化函数 */
function htmlInit(data) {
	var attachmentNum = 0;
	$("#teacher-name").html(data.appenddata.ajzTeacher.name);
	$("#card-text-photo-name").html("【" + data.appenddata.ajzTeacher.name + "】");
	$("#card-text-photo-img").attr("src", teacherImg + data.appenddata.ajzTeacher.liveRoomHeaderImg);
	$("#card-text-information-label").html(data.appenddata.ajzTeacher.identification);
	$("#card-text-information-p").html(data.appenddata.ajzTeacher.profiles);
	$("#card-text-information-more").attr("href", teacherSrc + data.appenddata.ajzTeacher.id);
	$("#card-text-school-logo").attr('src', 'image/schools/' + data.appenddata.ajzTeacher.schoolLogo + '.png');
	if (data.appenddata.ajzTeacher.isShowIndex == 0) {
		$('#card-text-information-more').hide();
	}
	if (data.appenddata.courseResources.length !== 0) {
		$.each(data.appenddata.courseResources, function(index, data) {
			if (data.category == 1 || data.category == 2) {
				var li = $("<li></li>");
				var nameSpan = $("<span class='card-attachment-text'></span>");
				var imgSpan = $("<span class='bg_sprite download-img'></span>");
				nameSpan.html(data.mark);
				li.attr("data-url", this.resourceUrl);
				li.append(nameSpan);
				li.append(imgSpan);
				$("ul#card-text-ul").append(li);
				attachmentNum++;
			}
		});
	}
	if (!attachmentNum) {
		$('#card-attachment').remove();
		$('.title-right-attachment').hover(function() {
			$('.title-right-attachment').css('color', '#685a86');
			$('.title-right-attachment-img').css('backgroundPosition', '-98px -50px');
		});
		$("#li-attachment").css({
			"cursor": "default"
		});
		$('#li-attachment').attr({
			'title': '无附件',
			'data-toggle': 'tooltip',
			'data-placement': 'bottom'
		});
		$('#li-attachment').tooltip();
	}
	$("ul#card-text-ul li:not(:first-child)").click(function() {
		window.open(courseResources + $(this).attr("data-url"));
	})
	if (data.appenddata.testCoursePaper != null) {
		serverObj['coursePaperId'] = data.appenddata.testCoursePaper.id;
		classEndTime = data.appenddata.testCoursePaper.starttime;
	} else {
		serverObj['coursePaperId'] = '';
		$('.title-right-test').attr({
			'title': '无小测',
			'data-toggle': 'tooltip',
			'data-placement': 'bottom'
		});
		$('.title-right-test').css('cursor', 'default');
		$('.title-right-test').tooltip();
	}

	if (data.appenddata.headMasterTeacher != null) {
		if (data.appenddata.headMasterTeacher.classType == 1) {
			$('#chat-btn').html('班级聊天');
			$(".openChat").show();
			headTeacherId = 'z' + data.appenddata.headMasterTeacher.id;
			$(".privateChat .ptc-title .t-header-img").attr("src", teacherImg + data.appenddata.headMasterTeacher.liveRoomHeaderImg);
		}
	}
	if(data.appenddata.liveGameSudokuStatus == 1){
		sudokuStatus = 1;
		signSuduku();
	} else if(data.appenddata.liveGameSudokuStatus == 0) {
		sudokuStatus = 0;
		$('.title-right-music').html('');
		$('.chat-title-split').hide();
		$('.chat-title-right').hide();
	} else if(data.appenddata.liveGameSudokuStatus == 2){
		sudokuStatus = 2;
		$('#music-btn').attr({
				'title': '您已经完成本次课前游戏啦',
				'data-toggle': 'tooltip',
				'data-placement': 'bottom'
				});
		$('#music-btn').tooltip();
	}
	if(data.appenddata.liveGameSudokuStatus) {
		data.appenddata.sudokuRank.map(function(user){
			addSudokuUser(user);
		})
		sortSudoku();
	}
}

/*课堂练习选项*/
$('#interactionModal').on('click','input[name="answer"]', function() {
	var sequence = $(this).val();
	if (1 == interarctionQuestionType) $('.question-label').removeClass('question-label-choose');
	if ($(this).is(":checked") == true) $('.question-label[for="sequence-' + sequence + '"]').addClass('question-label-choose');
	else $('.question-label[for="sequence-' + sequence + '"]').removeClass('question-label-choose');
});
/*题版练习选项*/
$('body').on('click','#persistent input[name="answerq"]', function() {
	var sequence = $(this).val();
	var type = $('#persistent').data('type');
	if (1 == type) $('#persistent .question-label').removeClass('question-label-choose');
	if ($(this).is(":checked") == true) $('#persistent .question-label[for="sequence2-' + sequence + '"]').addClass('question-label-choose');
		else $('#persistent .question-label[for="sequence2-' + sequence + '"]').removeClass('question-label-choose');
});
/*课后小测点击相应label点亮*/
$('#modal-middle').on('click', 'input.layout-option-change', function() {
	var sequence = $(this).attr('id');
	var name = $(this).attr('name');
	$('ul.question-option-choose-text-list[data-name="' + name + '"]').find('.question-option-label').removeClass('question-label-choose');
	if ($(this).is(":checked") == true) $('.question-option-label[for="' + sequence + '"').addClass('question-label-choose');
	else $('.question-option-label[for="' + sequence + '"]').removeClass('question-label-choose');
});
/* 课后小测打开 */
$("#postStart").click(function() {
	$("#judgeModal").modal('hide');
	ajaxRequest(serverObj, postTestInit, "/api/aa/getQuestion");
	$("#modalClose").click(function() {
		$("#judgeModal").modal('hide');
	});
});
/* 课后小测提交 */
$("#post-test-send-button").click(function() {
	var _length = $('#modal-post-test .modal-answer-num li').length;
	var _postest = serverObj;
	var _value = 0;
	for (var i = 0; i < _length; i++) {
		var x = $('#modal-post-test #answer-num-' + (i + 1)).find('input.layout-option-change:checked').val();
		if (x == undefined) {
			_value = 1;
			$('#modal-post-test .modal-answer-num li a#modal-answer-num-' + (i + 1))[0].click();
			return showCustomAlert('还有题目未作答！');
		}
	}
	if (_value == 1) {
		return;
	}
	_postest['type'] = $("#post-test-send-button").data("type");
	_postest['paperId'] = $("#post-test-send-button").data("paperId");

	function getScore() {
		ajaxRequest(serverObj, myPaper, "/api/aa/myPaper");

		function myPaper(data) {
			$('#modal-post-test').modal('hide');
			showCheckAnswer(data.appenddata);
		}
	}
	ajaxRequest(_postest, getScore, "/api/aa/getScore");

});

/* 吐槽 */
$("#discloseModal .modal-body ul li").click(function() {
	if ($(this).hasClass("disclose-active")) $(this).removeClass("disclose-active");
	else $(this).addClass("disclose-active");
	var choose = $(this).data("name");
	$("#discloseModal .modal-body ul").find("input#" + choose).click();
})
$("#disclose-send-button").click(function() {
	var discloseObj = serverObj;
	var discloseText = $("#disclose-text").val();
	var discloseTel = $("#disclose-tel").val();
	var discloseStr = "";
	$("#discloseModal input:checkbox[name='disclose-label']:checked").each(function(index) {
		if (0 == index) {
			discloseStr = $(this).val();
		} else {
			discloseStr += ("," + $(this).val());
		}
	});
	if (discloseText || discloseStr) {
		discloseObj['spitslotType'] = discloseStr;
		discloseObj['SpitslotContent'] = discloseText;
		discloseObj['spitslotQq'] = discloseTel;
		ajaxRequest(discloseObj, disclose, "/api/spitslot/addSpitslot");

		function disclose(data) {
			$("#discloseModal").modal('hide');
		}
	} else alert("请输入吐槽内容");
});

/*chat-nav-click*/
$("a#chat-btn,a#student-list").click(function() {
	if ($(this).css("color") !== "#fff") {
		$(this).parent().parent().find("span").animate({
			width: "0",
			left: "50%"
		}, 200);
		$("span", $(this).parent()).stop().animate({
			width: "70%",
			left: "15%",
			right: "15%"
		}, 200);
		$("a#chat-btn,a#student-list").css("color", "#625f68");
		$(this).css("color", "#fff");
	}
})

/* 课后评价 */
function starShow(i, target) {
	while (i > 0) {
		if (i % 2) {
			var x = (i + 1) / 2;
			$(target + x).addClass("half");
			i = i - 1;
		} else {
			var x = i / 2;
			$(target + x).addClass("one");
			i = i - 2;
		}
	}
}

function starHide(target) {
	$("." + target + " li").attr("class", "bg_sprite");
}

function contentImgshow(num, target) {
	$("#" + target).attr("class", "bg_sprite")
	$("#" + target).addClass("content-img-" + num);
}

$(".comment-content-star span").hover(function() {
	var i = $(this).data("value");
	contentImgshow(i, "comment-content-img");
	starShow(i, "#content-");
}, function() {
	starHide("comment-content-star");
	contentImgshow(0, "comment-content-img");
});
$(".comment-content-star span").click(function() {
	var i = $(this).data("value");
	$("#comment-content-value").val(i);
	contentImgshow(i, "comment-content-img");
	starHide("comment-content-star");
	starShow(i, "#content-");
	$(".comment-content-star span").off('mouseenter').unbind('mouseleave');
});

$(".comment-teacher-star span").hover(function() {
	var i = $(this).data("value");
	contentImgshow(i, "comment-teacher-img");
	starShow(i, "#teacher-");
}, function() {
	starHide("comment-teacher-star");
	contentImgshow(0, "comment-teacher-img");
});
$(".comment-teacher-star span").click(function() {
	var i = $(this).data("value");
	contentImgshow(i, "comment-teacher-img");
	$("#comment-teacher-value").val(i);
	starHide("comment-teacher-star");
	starShow(i, "#teacher-");
	$(".comment-teacher-star span").off('mouseenter').unbind('mouseleave');
});
$(".comment-degree li").click(function() {
	$(".comment-degree li").attr("class", "");
	$("#comment-degree-value").val($(this).data("type"));
	$(this).addClass("comment-degree-active");
});

/* 表情解析 */
var emojiObj = {
	"微笑": "image/emojis/smile.png",
	"可爱": "image/emojis/blush.png",
	"呲牙": "image/emojis/grin.png",
	"喜欢": "image/emojis/heart_eyes.png",
	"吐舌头": "image/emojis/stuck_out_tongue_closed_eyes.png",
	"调皮": "image/emojis/stuck_out_tongue_winking_eye.png",
	"激动": "image/emojis/joy.png",
	"不屑": "image/emojis/unamused.png",
	"哼": "image/emojis/smirk.png",
	"酷": "image/emojis/sunglasses.png",
	"呆": "image/emojis/neutral_face.png",
	"飞吻": "image/emojis/kissing_heart.png",
	"生气": "image/emojis/angry.png",
	"闪瞎": "image/emojis/astonished.png",
	"瞪眼": "image/emojis/flushed.png",
	"难受": "image/emojis/pensive.png",
	"愤怒": "image/emojis/rage.png",
	"纠结": "image/emojis/confounded.png",
	"怒": "image/emojis/triumph.png",
	"困": "image/emojis/sleeping.png",
	"吃惊": "image/emojis/fearful.png",
	"汗": "image/emojis/sweat.png",
	"惊恐": "image/emojis/scream.png",
	"大哭": "image/emojis/sob.png",
	"花": "image/emojis/rose.png",
	"西瓜": "image/emojis/watermelon.png",
	"一百分": "image/emojis/100.png",
	"厉害": "image/emojis/thumbsup.png",
	"ok": "image/emojis/ok_hand.png",
	"鼓掌": "image/emojis/clap.png",
	"胜利": "image/emojis/v.png",
	"祈祷": "image/emojis/pray.png",
	"不听": "image/emojis/hear_no_evil.png",
	"不说": "image/emojis/speak_no_evil.png",
	"不看": "image/emojis/see_no_evil.png",
	"魔性": "image/emojis/trollface.png"
}

function analyzeEmojis(msg) {
	var _msg = msg;
	var pattern = /\[(\w|[\u4e00-\u9fa5])+\]/g;
	var str = _msg.replace(pattern, function(word) {
		var reg = /(\w|[\u4e00-\u9fa5])+/g;
		var content = word.match(reg)[0];
		var _obj;
		for (var x in emojiObj) {
			if (x == content) {
				var src = emojiObj[x];
				_obj = "<img src='" + src + "'>";
			}
		}
		return _obj;
	})
	return str;
}

//发送私聊信息
function sendChat() {
	var privateChat = $("#chatContent").val(); 

	if ($.trim(privateChat) == '') {
		alert('输入内容不能为空');
		return;
	}
	LMC.sendCustomMsg({
		"type": "privateChat",
		'data': {
			'flag': 'privateChat',
			'content': LMC.tools.jsonStringify({
				'userId': headTeacherId,
				'role': role,
				'content': $.trim(privateChat),
			})
		}
	});
	$("#chatContent").val("");
	if ($("#chatContent").val().length > 0) $('.ptc-foot .ft-submit').css('backgroundColor', '#685a86');
	else $('.ptc-foot .ft-submit').css('backgroundColor', '#d7d7d7');
	$("#chatContent").focus();
}

//私聊内容渲染
function showPrivateMsg(msgData) {
	if (msgData.msgData.flag == 'privateChat') {
		var str = msgData.msgData.content;
		var tId = msgData.userData.userId;
		var tname = msgData.userData.userId;
		var data = LMC.tools.parseJson(str);
		var uId = data.userId;
		var role = data.role;
		var content = analyzeEmojis(data.content);
		if (tId == userId) {
			var $li = $("<li class='ptc-uone'></li>");
			var unameTxt = "";
			if (role == 'student') {
				unameTxt = '<div class="ptc-uname">' + nickname + '</div>';
			} else if (role == 'zj') {
				unameTxt = '<div class="ptc-uname">班主任</div>';
			}
			var ctnTxt = '<div class="ptc-ctn">' + content + '</div><div class="triangle-topleft"></div>';
			$li.append(unameTxt);
			$li.append(ctnTxt);
			$(".ptc-row").append($li);
		}
		if (userId == uId) {
			var $li = $("<li class='ptc-uone'></li>");
			var unameTxt = "";
			if (role == 'student') {
				unameTxt = '<div class="ptc-tname">' + nickname + '</div>';
			} else if (role == 'zj') {
				unameTxt = '<div class="ptc-tname">班主任</div>';
			}
			var ctnTxt = '<div class="ptc-ttn">' + content + '</div><div class="triangle-topright"></div>';
			$li.append(unameTxt);
			$li.append(ctnTxt);
			$(".ptc-row").append($li);
			if ($(".privateChat").css("display") == "none") {
				$(".openChat").addClass('shake');
				$(".red-point").show();
			}
		}
		if ($('.ptc-row').find('li').length > 50) {
			$('.ptc-row').find('li').eq(0).remove();
		}
	}
}
//关闭私聊窗口
function closeChat() {
	$(".privateChat").hide();
	$(".openChat").show();
}

//打开私聊窗口
function openChat() {
	$(".openChat").removeClass('shake');
	$(".red-point").hide();
	$(".privateChat").show();
	$(".openChat").hide();
}
/* 私聊回车事件 */
$("#chatContent").keypress(function(event) {
	e = event ? event : (window.event ? window.event : null);
	if (e.keyCode == 13 && !e.ctrlKey) {
		event.preventDefault();
		sendChat();
	}
});
/* 输入内容后改变发送按键 */
$("#chatContent").on('input propertychange', function() {
	if ($("#chatContent").val().length > 0) $('.ptc-foot .ft-submit').css('backgroundColor', '#685a86');
	else $('.ptc-foot .ft-submit').css('backgroundColor', '#d7d7d7');
});

$(function() {
	/*if (LMC.getStatus().bgmusic == "play") {
		LMC.playAudio({
			status: 'switch'
		});
	}*/
	$(".openChat").hover(function() {
		$(".openChat img").attr("src", "image/icons/chat_2.png");
	}, function() {
		$(".openChat img").attr("src", "image/icons/chat_1.png");
	});
})

/* 侧栏回看题版 */
function answerItem(data) {
	_answerItem = this;
	this.data = data;
	this._index = 0;
	this.ul = $('.answer-item-list');
	this.li = $('<li><div class="status"></div><p class="answer-item-name">第<span class="answer-item-name-num"></span>题</p><p class="answer-item-time"><span class="answer-item-time-start"></span>-<span class="answer-item-time-end"></span></p></li>');	
	this.buttonTime = 0;
	this.startTime = 0;
	this.endTime = 0;
	this.setUlData();
	$('div.XuanZe').hide();
	$('div.TianKong').hide();
	$('body').on('click','.answer-item-close',function() {
		_answerItem.clickClose();
	});
	$('body').on('click','.answer-item-icons',function(){
		_answerItem.clickOpen($(this).attr('selfAnswer'),$(this).attr('rightAnswer'));
	});
	$('body').on('click','.answer-item-list li',function() {
		_answerItem.openPersistent($(this).data('id'));
	});
	$('#persistent').on('click','.close',function() {
		_answerItem.closePersistent();

	});
	$('#persistent').on('click','#answer-send-button',function() {
		_answerItem.sumbitAnswer();

	});
}
answerItem.prototype = {
	constructor:answerItem,
	moveLeft: function() {},
	moveRight: function() {},
	clickClose: function() {
		_answerItem.slideLeftHide($('.answer-item'),600,function(){
			$('.answer-item-icons').show();
		});
		var time = {
			'time': (new Date()).getTime()
		};
		_answerItem.sumbitCommand('playbackSidebarStatus','close',time);
	},
	clickOpen: function() {
		$('.answer-item-icons').hide();
		_answerItem.slideLeftShow($('.answer-item'),600,function(){
		});
		var time = {
			'time': (new Date()).getTime()
		};
		_answerItem.sumbitCommand('playbackSidebarStatus','open',time);
	},
	slideLeftHide: function(obj,speed,callback) {
		$(obj).animate({    
            width : "hide",    
            paddingLeft : "hide",    
            paddingRight : "hide",    
            marginLeft : "hide",
            marginRight : "hide"
        }, speed, callback );
	},
	slideLeftShow: function(obj,speed,callback) {
		$(obj).animate({    
            width : "show",    
            paddingLeft : "show",    
            paddingRight : "show",    
            marginLeft : "show",    
            marginRight : "show"
        }, speed, callback );
	},
	timeChange: function(mtime,rtime) {
		var _rtime = rtime || 0;
		var time = mtime - _rtime < 0 ? 0 : mtime - _rtime;
		var hh = parseInt(time / 1000 / 60 / 60 % 24, 10);
		var mm = parseInt(time / 1000 / 60 % 60, 10);
		var ss = parseInt(time / 1000 % 60, 10);
		// 		dd = dd<10?("0" + dd):dd;   //天  
		hh = hh < 10 ? ("0" + hh) : hh; //时  
		mm = mm < 10 ? ("0" + mm) : mm; //分  
		ss = ss < 10 ? ("0" + ss) : ss; //秒 
		return hh + ':' + mm + ':' + ss;
	},
	/* 生成li */
	setLiData: function(question,index) {
		var _li = _answerItem.li.clone();
		var startTime = _answerItem.timeChange(question.liveQUestionResults[0].pushStartTime);
		var endTime = _answerItem.timeChange(question.liveQUestionResults[0].pushEndTime);
		_li.data('id',question.id);
		_li.find('.answer-item-name-num').html(index);
		_li.find('.answer-item-time-start').html(startTime);
		_li.find('.answer-item-time-end').html(endTime);
		return _li;
	},
	/* 生成ul */
	setUlData: function() {
		var list = _answerItem.data;
		for(var i = 0; i < list.length;i++) {
			var x =  _answerItem.setLiData(list[i],i + 1);
			_answerItem.ul.append(x);
		}
	},
	/* 打开题目面板 */
	openPersistent: function(id) {
		var _answer = {};
		var answerContent = '';
		for(var i = 0;i < _answerItem.data.length;i++) {
			if(_answerItem.data[i].id == id) {
				_answer = _answerItem.data[i];
				_answerItem._index = i;
			}
		}
		if(JSON.stringify(_answer) == "{}") return alert('无此题');
		$('#persistent').data('type',_answer.questionType);
		if (1 == _answer.questionType || 2 == _answer.questionType) {
		if (2 == _answer.questionType) $(".answer-PanDuan-type p").html("多选题");
		else $(".answer-PanDuan-type p").html("单选题");
		$('.content').html(_answer.questionContent);
		if (_answer.liveQuestionAttachs !== null && _answer.liveQuestionAttachs.length !== 0) {
			$(_answer.liveQuestionAttachs).each(function() {
				$('<img src="" style="max-width:180px;margin: 20px 0 0 10px;">').attr('src', questionImg + this.url).appendTo("#persistent .modal-body-img");
			})
		}
		$(_answer.liveQuestionAnswers).each(function() {
			var $item = $('<div class="row"></div>');
			$item.append('<label><input value="" data-type="interaction" type="radio" class="layout-change" name="answerq" style="display:none;"><span class="answer-index"></span><span class="answer-content"></span></label>');
			$item.find('input').attr('value', this.sequence);
			$item.find('input').attr('id', 'sequence2-' + this.sequence);
			if (2 == _answer.questionType) $item.find('input').attr('type', 'checkbox');
			$item.find('.answer-index').html(this.sequence);
			$item.find('.answer-content').html('      ' + this.answer);
			$('#persistent .answer-list').append($item);
			var $list = $('<li><label class="question-label" for=""></label></li>');
			$list.find('label').html(this.sequence);
			$list.find('label').attr('for', 'sequence2-' + this.sequence);
			$('#persistent .question-choose-text-list').append($list);
			if(this.isright == 1) {
				if (!answerContent) answerContent = this.sequence;
				else answerContent += ',' + this.sequence;
			}
		});
		$('div.XuanZe').show();
	} else if (3 == _answer.questionType) {
		/*$('input[name="answer"]').val('');*/
		$('#answer-input').val('');
		$('.answer-content').html(_answer.questionContent);
		if (_answer.liveQuestionAttachs !== null && _answer.liveQuestionAttachs.length !== 0) {
			$(_answer.liveQuestionAttachs).each(function() {
				$('<img src="" style="max-width:180px;margin: 20px 0 0 10px;">').attr('src', questionImg + this.url).appendTo(".answer-img");
			})
		}
		$('.question-choose-text-list').append('<input type="text" placeholder="" class="form-control" id="answer-item-input-area" name="tkanswerq">');
		if (_answer.remark) {
			$('#answer-input-area').attr('placeholder', _answer.remark);
		} else $('#answer-input-area').attr('placeholder', '请输入答案');
		answerContent = _answer.liveQuestionAnswers[0].answer;
		$('div.TianKong').show();
	}
		$('#persistent-right-answer').html(answerContent);
		if(_answer.hasOwnProperty('answer')) {
			$('#persistent-your-answer').html(_answer.answer);
			_answerItem.openAnswer();
		}
		var time = {
			'time': (new Date()).getTime(),
			'question': _answerItem.data[_answerItem._index]
		};
		_answerItem.sumbitCommand('playbackQuestion','open',time);
		var mathId = document.getElementById("persistent");
		MathJax.Hub.Config({
			tex2jax: {
				inlineMath: [
					['$', '$'],
					["\\(", "\\)"]
				],
				displayMath: [
					['$$', '$$'],
					["\\[", "\\]"]
				]
			}
		});
	MathJax.Hub.Queue(["Typeset", MathJax.Hub, mathId]);
		$('#persistent').modal({
			'show': true,
			'backdrop': 'static',
			'keyboard': false
		});
	},
	openAnswer: function(selfAnswer,rightAnswer) {
		$('#persistent .modal-footer').hide();
		$('#persistent .modal-footer-2').show();
	},
	sumbitAnswer: function(question) {
		var type = $('#persistent').data('type');
		var answer = '';
		if (3 == type) {
			answer = $('#persistent input[name="tkanswerq"]').val();
		} else if (1 == type) {
			answer = $('#persistent input[name="answerq"]:checked').val();
		} else if (2 == type) {
			$('#persistent input[name="answerq"]:checked').each(function() {
				if (!answer)
					answer = $(this).val();
				else answer += ',' + $(this).val();
			});
		}
		if (!answer) {
			showCustomAlert('请输入答案');
			return;
		}
		var time = {
			'time': (new Date()).getTime(),
			'question': _answerItem.data[_answerItem._index]
		};
		_answerItem.sumbitCommand('playbacksumbit','sumbit',time);

		_answerItem.data[_answerItem._index]['answer'] = answer;
		$('#persistent-your-answer').html(answer);
		_answerItem.ul.find('li').eq(_answerItem._index).find('div.status').addClass('status-choose');
		_answerItem.openAnswer();
	},
	closePersistent: function() {
		$('div#persistent .answer-PanDuan-type p').html();
		$('div#persistent div.XuanZe').hide();
		$('div#persistent div.TianKong').hide();
		$("div#persistent .modal-body-img").children().remove();
		$("div#persistent .answer-img").children().remove();
		$("div#persistent .question-choose-text-list").children().remove();
		$('div#persistent .answer-list').empty();
		$('div#persistent .answer-content').empty();
		$('div#persistent .modal-body').hide();
		$('div#persistent .modal-footer-2').hide();
		$('div#persistent .modal-footer').show();
		var time = {
			'time': (new Date()).getTime(),
			'question': _answerItem.data[_answerItem._index]
		};
		_answerItem.sumbitCommand('playbackQuestion','close',time);
	},
	sumbitCommand: function(type,status,content) {
		var xcontent = {};
		xcontent['status'] = status;
		xcontent['content'] = JSON.stringify(content);
		serverObj['content'] = '';
		serverObj['type'] = type;
		serverObj['userName'] = nickname;
		serverObj.content = JSON.stringify(xcontent);
		ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
	}
}







$('body').on('click','#card-text-information-more',function(e) {
	var xcontent = {'href': $(e).attr('href')};
	serverObj['content'] = '';
	serverObj['type'] = 'information-more';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#postStart',function(e) {
	var xcontent = {};
	serverObj['content'] = '';
	serverObj['type'] = 'postStart';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#postEnd',function(e) {
	var xcontent = {};
	serverObj['content'] = '';
	serverObj['type'] = 'postEnd';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#card-text-ul li',function(e) {
	var xcontent = {'href': $(e).attr('href')};
	serverObj['content'] = '';
	serverObj['type'] = 'attachment';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#snedLikeBtn',function(e) {
	var xcontent = {};
	serverObj['content'] = '';
	serverObj['type'] = 'like';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#snedFlowerBtn',function(e) {
	var xcontent = {};
	serverObj['content'] = '';
	serverObj['type'] = 'flower';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})
$('body').on('click','#student-list',function(e) {
	var xcontent = {};
	serverObj['content'] = '';
	serverObj['type'] = 'sudoku-button';
	serverObj['userName'] = nickname;
	serverObj.content = JSON.stringify(xcontent);
	ajaxRequest(serverObj,function(){},'/api/liveLog/addLiveLog',true);
})