VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "打卡提醒设置工具"
   ClientHeight    =   3720
   ClientLeft      =   150
   ClientTop       =   780
   ClientWidth     =   6150
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   3720
   ScaleWidth      =   6150
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame Frame3 
      Caption         =   "提示启用时间段设置"
      Height          =   1095
      Left            =   45
      TabIndex        =   22
      Top             =   2565
      Width           =   6045
      Begin VB.OptionButton Option1 
         Caption         =   "时间段2"
         Height          =   240
         Index           =   1
         Left            =   315
         TabIndex        =   12
         Top             =   630
         Width           =   1185
      End
      Begin VB.OptionButton Option1 
         Caption         =   "时间段1"
         Height          =   240
         Index           =   0
         Left            =   315
         TabIndex        =   11
         Top             =   315
         Width           =   1185
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   8
         Left            =   2340
         TabIndex        =   15
         Top             =   630
         Width           =   870
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   9
         Left            =   3645
         TabIndex        =   16
         Top             =   630
         Width           =   870
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   6
         Left            =   2340
         TabIndex        =   13
         Top             =   225
         Width           =   870
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   7
         Left            =   3645
         TabIndex        =   14
         Top             =   225
         Width           =   870
      End
      Begin VB.CommandButton Command_PromotTime 
         Caption         =   "设置时间段"
         Height          =   675
         Left            =   4950
         TabIndex        =   17
         Top             =   225
         Width           =   945
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "结束：                    时                         分"
         Height          =   195
         Index           =   3
         Left            =   1845
         TabIndex        =   24
         Top             =   675
         Width           =   2925
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "起始：                    时                         分"
         Height          =   195
         Index           =   2
         Left            =   1845
         TabIndex        =   23
         Top             =   270
         Width           =   2925
      End
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   3735
      Top             =   135
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
      RThreshold      =   15
      InputMode       =   1
   End
   Begin VB.Frame Frame2 
      Caption         =   "时间调整"
      Height          =   1320
      Left            =   45
      TabIndex        =   19
      Top             =   1170
      Width           =   6045
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   10
         Left            =   3645
         TabIndex        =   5
         Top             =   353
         Width           =   645
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   5
         Left            =   2340
         TabIndex        =   8
         Top             =   825
         Width           =   645
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   4
         Left            =   1395
         TabIndex        =   7
         Top             =   825
         Width           =   645
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   3
         Left            =   90
         TabIndex        =   6
         Top             =   825
         Width           =   870
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   2
         Left            =   2340
         TabIndex        =   4
         Top             =   353
         Width           =   645
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   1
         Left            =   1395
         TabIndex        =   3
         Top             =   353
         Width           =   645
      End
      Begin VB.TextBox Text1 
         Height          =   285
         Index           =   0
         Left            =   90
         TabIndex        =   2
         Top             =   353
         Width           =   870
      End
      Begin VB.CommandButton Command_ReadComputerTime 
         Caption         =   "同步计算机时间"
         Height          =   360
         Left            =   4365
         TabIndex        =   10
         Top             =   787
         Width           =   1530
      End
      Begin VB.CommandButton Command_SetTime 
         Caption         =   "设置时间"
         Height          =   360
         Left            =   4905
         TabIndex        =   9
         Top             =   315
         Width           =   990
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "时                   分                 秒"
         Height          =   195
         Index           =   1
         Left            =   1035
         TabIndex        =   21
         Top             =   870
         Width           =   2160
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "年                   月                 日.星期"
         Height          =   195
         Index           =   0
         Left            =   1035
         TabIndex        =   20
         Top             =   405
         Width           =   2580
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "设备信息"
      Height          =   1050
      Left            =   45
      TabIndex        =   0
      Top             =   45
      Width           =   6045
      Begin VB.CommandButton cmd_ReadPara 
         Caption         =   "读取信息"
         Default         =   -1  'True
         Height          =   675
         Left            =   5220
         TabIndex        =   1
         Top             =   225
         Width           =   630
      End
      Begin VB.Label LabelDispPara 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "----"
         Height          =   195
         Left            =   270
         TabIndex        =   18
         Top             =   315
         Width           =   240
      End
   End
   Begin VB.Menu Ref 
      Caption         =   "刷新"
   End
   Begin VB.Menu Uart 
      Caption         =   "串口"
      Begin VB.Menu UartX1 
         Caption         =   "COM1"
         Index           =   0
      End
   End
   Begin VB.Menu Baud 
      Caption         =   "波特率"
      Begin VB.Menu bps 
         Caption         =   "9600bps"
         Index           =   0
      End
      Begin VB.Menu bps 
         Caption         =   "19200bps"
         Index           =   1
      End
      Begin VB.Menu bps 
         Caption         =   "38400bps"
         Index           =   2
      End
   End
   Begin VB.Menu status 
      Caption         =   "status"
      Enabled         =   0   'False
      Visible         =   0   'False
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim COMBaud As String
Dim COMPort  As Integer

 

Private Sub bps_Click(Index As Integer)
    Select Case Index
    
        Case 0
            COMBaud = "9600"
        Case 1
            COMBaud = "19200"
        Case 2
            COMBaud = "38400"
    End Select
    
    Call SetMSCOMM
    
End Sub

Function SetMSCOMM()
    On Error Resume Next
    
    
    If MSComm1.PortOpen = True Then
        MSComm1.PortOpen = False
    End If
   
    MSComm1.CommPort = COMPort
    MSComm1.Settings = COMBaud & ",n,8,1"
    MSComm1.PortOpen = True
    If Err Then
        MsgBox Err.Number & Err.Description, vbInformation + vbOKOnly
        Err.Clear
        status.Caption = ""
        status.Enabled = False
        status.Visible = False
    End If
    status.Caption = "串口已打开:" & COMBaud & "bps@" & "COM" & COMPort
    status.Visible = True
    status.Enabled = False
End Function

Private Sub cmd_ReadPara_Click()
    Dim UartData(4) As Byte
    UartData(0) = &H59
    UartData(1) = &H75
    UartData(2) = &H68
    UartData(3) = &H74
    UartData(4) = 4
    MSComm1.RThreshold = 15
    MSComm1.Output = UartData()
End Sub

Private Sub Command_PromotTime_Click()
    If Option1(0).Value = False And Option1(1).Value = False Then
        MsgBox "选择时间段!", vbOKOnly + vbInformation
        Exit Sub
    End If
    
    If Text1(6) > 23 Or Text1(6) < 0 Or _
        Text1(8) > 23 Or Text1(8) < 0 Or _
        Text1(7) > 59 Or Text1(7) < 0 Or _
        Text1(9) > 59 Or Text1(9) < 0 Then
        MsgBox "参数超范围", vbInformation + vbOKOnly
        Exit Sub
    End If
    
    
    If Len(Text1(6)) = 0 Or _
        Len(Text1(8)) = 0 Or _
        Len(Text1(7)) = 0 Or _
        Len(Text1(9)) = 0 Then
        MsgBox "不许为空", vbInformation + vbOKOnly
        Exit Sub
    End If
    
    
    Dim intA(8) As Byte
    intA(0) = &H59
    intA(1) = &H75
    intA(2) = &H68
    intA(3) = &H74
    intA(4) = 2 + IIf(Option1(0).Value = True, 0, 1)
    intA(5) = Text1(6)
    intA(6) = Text1(7)
    intA(7) = Text1(8)
    intA(8) = Text1(9)
    MSComm1.Output = intA()
    
End Sub

Private Sub Command_ReadComputerTime_Click()
    Text1(0) = Year(Now)
    Text1(1) = Month(Now)
    Text1(2) = Day(Now)
    Text1(3) = Hour(Now)
    Text1(4) = Minute(Now)
    Text1(5) = Second(Now)
    Text1(10) = Weekday(Date, vbMonday)
    Call Command_SetTime_Click
    
End Sub


Private Sub Command_SetTime_Click()
    If Len(Text1(0)) = 0 Or _
        Len(Text1(1)) = 0 Or _
        Len(Text1(2)) = 0 Or _
        Len(Text1(3)) = 0 Or _
        Len(Text1(4)) = 0 Or _
        Len(Text1(5)) = 0 Or _
        Len(Text1(10)) = 0 Then
        
        MsgBox "不许为空!", vbOKOnly + vbInformation
        Exit Sub
    End If
    Dim intA(11) As Byte
    intA(0) = &H59
    intA(1) = &H75
    intA(2) = &H68
    intA(3) = &H74
    intA(4) = 1
    intA(5) = Text1(5)
    intA(6) = Text1(4)
    intA(7) = Text1(3)
    intA(8) = Text1(10)
    intA(9) = Text1(2)
    intA(10) = Text1(1)
    intA(11) = Right(Text1(0), 2)
    
    MSComm1.Output = intA()
End Sub

Private Sub Form_Load()
    Dim i As Integer, j As Integer
    i = 0
    j = 0
    On Error Resume Next
    COMBaud = "9600"
    MSComm1.Settings = COMBaud & ",n,8,1"
    For j = 1 To 256
        MSComm1.CommPort = j
        MSComm1.PortOpen = True
        If Err.Number = 0 Then
            If i <> 0 Then
                Load UartX1(i)
            End If
            UartX1(i).Caption = "COM" & j
            UartX1(i).Visible = True
            i = i + 1
        End If
        
        If MSComm1.PortOpen = True Then
            MSComm1.PortOpen = False
        End If
        Err.Clear
    Next
    If i = 0 Then '无可用串口
        Uart.Visible = False
        Baud.Visible = False
        status.Caption = 0
        status.Visible = False
        '
        Command_SetTime.Enabled = False
        Command_ReadComputerTime.Enabled = False
        Command_PromotTime.Enabled = False
        cmd_ReadPara.Enabled = False
        '
        Exit Sub
    End If
    Uart.Visible = True
    Baud.Visible = True
    '
    Command_SetTime.Enabled = True
    Command_ReadComputerTime.Enabled = True
    Command_PromotTime.Enabled = True
    cmd_ReadPara.Enabled = True
    '
    COMPort = CInt(Replace$(UCase(UartX1(0).Caption), "COM", ""))
    Call SetMSCOMM
    LabelDispPara = ""
End Sub


Private Sub MSComm1_OnComm()
    
    
    If MSComm1.CommEvent = comEvReceive Then
        Dim intA() As Byte '十六进制转换中间变量
        intA() = MSComm1.Input
        
        Dim j As Integer
        Debug.Print "____"
        For j = 0 To UBound(intA())
            Debug.Print intA(j);
        Next
        
        If UBound(intA()) = 14 Then
            LabelDispPara = _
            "时    间  :  " & Format(intA(6), "00") & "年" & _
                    Format(intA(5), "00") & "月" & _
                    Format(intA(4), "00") & "日.星期" & _
                    intA(3) & ". " & _
                    Format(intA(2), "00") & ":" & _
                    Format(intA(1), "00") & ":" & _
                    Format(intA(0), "00") & vbCrLf & _
            "时间段1:  " & Format(intA(7), "00") & ":" & Format(intA(8), "00") & "--" & Format(intA(9), "00") & ":" & Format(intA(10), "00") & vbCrLf & _
            "时间段2:  " & Format(intA(11), "00") & ":" & Format(intA(12), "00") & "--" & Format(intA(13), "00") & ":" & Format(intA(14), "00")
            
        End If
        
        

    End If

End Sub

Private Sub Option1_Click(Index As Integer)
    Option1(Index).Value = 1
End Sub

Private Sub Ref_Click()
    Call Form_Load
End Sub

Private Sub UartX1_Click(Index As Integer)
    COMPort = CInt(Replace$(UCase(UartX1(Index).Caption), "COM", ""))
    Debug.Print COMPort
    Call SetMSCOMM
End Sub
