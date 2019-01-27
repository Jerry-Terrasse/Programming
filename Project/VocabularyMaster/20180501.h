/*battery 
英/'bætri/  美/'bæt(ə)rɪ/  全球(美国)  
简明 朗文 柯林斯 21世纪 例句 百科
n. [电] 电池，蓄电池
n. [法]殴打
n. [军]炮台，炮位*/
/*record 
英/(for v.)rɪˈkɔːd; (for n.) ˈrekɔːd/  美/(for v.) rɪˈkɔrd; (for n.) ˈrekərd;ˈrɛkɚd/  全球(美国)  
简明 朗文 柯林斯 21世纪 例句 百科
vt. 记录，记载；标明；将...录音
vi. 记录；录音
n. 档案，履历；唱片；最高纪录
adj. 创纪录的
n. (Record)人名；(法)勒科尔；(英)雷科德*/
/*in
英 /ɪn/  美 /ɪn/
prep. 按照（表示方式）；从事于；在…之内
adv. 进入；当选；（服装等）时髦；在屋里
adj. 在里面的；时髦的
n. 执政者；门路；知情者
n. (In)人名；(中)演(广东话·威妥玛)；(柬)殷(用于名字第一节)， 因；(日)寅 (名)
过去式inned
过去分词inned
现在分词inning*/
/*(@*)(#&)($^)(%%)
index
@
  #name##pncE#pncA#member.size
*
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int load();
struct word
{
	string ppt;//porperty
  vector<string>prf;//paraphrase
};
struct group
{
	int index;
	string name;
	string pncE,pncA;//pronuncioation
	vector<word>member;
};
//group dft;//default
int amt=0;//amount
vector<group>lbr;//library
ifstream fin("a.dll");
int main()
{
	
	return 0;
}
int load()
{
	int i=0;
	group a
	fin>>amt;
	for(i=0;i<amt;i++)
	{
		
	}
	return 0;
}