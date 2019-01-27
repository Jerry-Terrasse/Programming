VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   10950
   ClientLeft      =   -90
   ClientTop       =   450
   ClientWidth     =   20250
   LinkTopic       =   "Form1"
   ScaleHeight     =   10950
   ScaleWidth      =   20250
   Begin VB.OptionButton Org 
      Caption         =   "Option1"
      Height          =   255
      Left            =   1080
      TabIndex        =   0
      Top             =   840
      Width           =   255
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Const bla As Long = 100
Dim mx As Long, s(2 * bla - 1) As Double
Private Sub Form_Load()
 Org.Top = Form1.Height \ 2 - 500
 Org.Left = Form1.Width \ 2 - 500
 mx = 2 * Org.Left
End Sub
Private Function alive(x As Double) As Boolean
 If False Then
  alive = False
 Else
  alive = True
 End If
End Function
Private Function fuc(x As Double) As Double
 If alive(x) Then
  fuc = x * x * x + 2 * x * x + 8
' Else
'  fuc = 9999998
 End If
End Function
Private Sub Org_Click()
 Form1.Line (100, Org.Top)-(mx, Org.Top)
 Form1.Line (Org.Left, 100)-(Org.Left, Form1.Height - 500)
 Call work
 'MsgBox "Worked."
 Call drow
 'Form1.Line (500, 500)-(2500, 2500)
 'MsgBox "Drowed."
 'Form1.Line (500, 500)-(4654, 5465)
End Sub
Private Sub work()
 Dim i As Long
 For i = 0 To 2 * bla - 1
  s(i) = fuc(i - bla)
 Next i
End Sub
Private Sub drow()
 Dim i As Long, xx1 As Long, xx2 As Long, yy1 As Long, yy2 As Long
 For i = 0 To 2 * bla - 2
  xx1 = Org.Left + (i - bla) * mx / (2 * bla - 1)
  yy1 = Org.Top - s(i) * mx / (2 * bla - 1)
  xx2 = Org.Left + (i - bla + 1) * mx / (2 * bla - 1)
  yy2 = Org.Top - s(i + 1) * mx / (2 * bla - 1)
  Form1.Line (xx1, yy1)-(xx2, yy2)
  'MsgBox xx1 & "," & yy1 & "-" & xx2 & "," & yy2
 ' Form1.Line (Org.Left + (i - bla) * mx / (2 * bla - 1), Org.Top + s(i) * mx / (2 * bla - 1))-(Org.Left + (i - bla + 1) * mx / (2 * bla - 1), Org.Top + s(i + 1) * mx / (2 * bla - 1))
 Next i
End Sub
