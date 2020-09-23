VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "Mscomctl.ocx"
Begin VB.Form frmMain 
   BackColor       =   &H00E0E0E0&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "UltimaX Terrain Texture Generator"
   ClientHeight    =   4455
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   8730
   Icon            =   "frmMain.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   297
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   582
   StartUpPosition =   2  'CenterScreen
   Begin MSComDlg.CommonDialog CD 
      Left            =   0
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame HMFrame 
      BackColor       =   &H00E0E0E0&
      Height          =   825
      Left            =   4440
      TabIndex        =   4
      Top             =   30
      Width           =   4215
      Begin VB.TextBox txtHeightMapFilename 
         Height          =   285
         Left            =   480
         TabIndex        =   7
         Top             =   440
         Width           =   3615
      End
      Begin VB.CommandButton cmdOpenHeightmap 
         Height          =   300
         Left            =   120
         Picture         =   "frmMain.frx":08CA
         Style           =   1  'Graphical
         TabIndex        =   5
         Top             =   430
         Width           =   300
      End
      Begin VB.Label lblOHM 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Heightmap"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   6
         Top             =   165
         Width           =   885
      End
   End
   Begin VB.VScrollBar VScroll 
      Enabled         =   0   'False
      Height          =   4110
      Left            =   4215
      Max             =   1
      TabIndex        =   3
      Top             =   120
      Width           =   165
   End
   Begin VB.HScrollBar HScroll 
      Enabled         =   0   'False
      Height          =   165
      Left            =   120
      Max             =   1
      TabIndex        =   2
      Top             =   4200
      Width           =   4110
   End
   Begin VB.PictureBox picCont 
      Appearance      =   0  'Flat
      BackColor       =   &H00C0C0C0&
      ForeColor       =   &H80000008&
      Height          =   4110
      Left            =   120
      ScaleHeight     =   272
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   272
      TabIndex        =   0
      Top             =   120
      Width           =   4110
      Begin VB.PictureBox Canvas 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   3840
         Left            =   120
         ScaleHeight     =   256
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   256
         TabIndex        =   1
         Top             =   120
         Width           =   3840
      End
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H00E0E0E0&
      Height          =   825
      Left            =   4440
      TabIndex        =   18
      Top             =   825
      Width           =   4215
      Begin VB.CommandButton cmdOpenL 
         Enabled         =   0   'False
         Height          =   300
         Left            =   120
         Picture         =   "frmMain.frx":09CC
         Style           =   1  'Graphical
         TabIndex        =   20
         Top             =   430
         Width           =   300
      End
      Begin VB.TextBox txtLowerF 
         Enabled         =   0   'False
         Height          =   285
         Left            =   480
         TabIndex        =   19
         Top             =   440
         Width           =   3615
      End
      Begin VB.Label Label8 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Lower Altitude Map"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   21
         Top             =   165
         Width           =   1620
      End
   End
   Begin VB.Frame Frame3 
      BackColor       =   &H00E0E0E0&
      Height          =   825
      Left            =   4440
      TabIndex        =   22
      Top             =   1620
      Width           =   4215
      Begin VB.CommandButton cmdOpenU 
         Enabled         =   0   'False
         Height          =   300
         Left            =   120
         Picture         =   "frmMain.frx":0ACE
         Style           =   1  'Graphical
         TabIndex        =   24
         Top             =   430
         Width           =   300
      End
      Begin VB.TextBox txtUpperF 
         Enabled         =   0   'False
         Height          =   285
         Left            =   480
         TabIndex        =   23
         Top             =   440
         Width           =   3615
      End
      Begin VB.Label Label9 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Higher Altitude Map"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   25
         Top             =   165
         Width           =   1620
      End
   End
   Begin VB.Frame Frame1 
      BackColor       =   &H00E0E0E0&
      Height          =   840
      Left            =   4440
      TabIndex        =   8
      Top             =   2415
      Width           =   4215
      Begin VB.TextBox txtLIntesity 
         Alignment       =   2  'Center
         Height          =   285
         Left            =   3495
         TabIndex        =   17
         Text            =   "0.1"
         Top             =   400
         Width           =   495
      End
      Begin VB.TextBox txtLPos 
         Alignment       =   2  'Center
         Height          =   285
         Index           =   2
         Left            =   2040
         TabIndex        =   13
         Text            =   "0.0"
         Top             =   400
         Width           =   495
      End
      Begin VB.TextBox txtLPos 
         Alignment       =   2  'Center
         Height          =   285
         Index           =   1
         Left            =   1200
         TabIndex        =   12
         Text            =   "-20.0"
         Top             =   400
         Width           =   495
      End
      Begin VB.TextBox txtLPos 
         Alignment       =   2  'Center
         Height          =   285
         Index           =   0
         Left            =   360
         TabIndex        =   11
         Text            =   "0.0"
         Top             =   400
         Width           =   495
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Intensity"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   2760
         TabIndex        =   16
         Top             =   435
         Width           =   720
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Z"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   1920
         TabIndex        =   15
         Top             =   435
         Width           =   105
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Y"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   1080
         TabIndex        =   14
         Top             =   435
         Width           =   105
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "X"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   240
         TabIndex        =   10
         Top             =   435
         Width           =   105
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Light Parameters"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   120
         TabIndex        =   9
         Top             =   165
         Width           =   1440
      End
   End
   Begin VB.Frame Frame4 
      BackColor       =   &H00E0E0E0&
      Height          =   1155
      Left            =   4440
      TabIndex        =   26
      Top             =   3225
      Width           =   4215
      Begin VB.OptionButton optExportType 
         Caption         =   "TGA"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   1
         Left            =   3000
         TabIndex        =   32
         Top             =   180
         Value           =   -1  'True
         Width           =   735
      End
      Begin VB.OptionButton optExportType 
         Caption         =   "BMP"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   0
         Left            =   1920
         TabIndex        =   31
         Top             =   180
         Width           =   735
      End
      Begin VB.CommandButton cmdRender 
         Caption         =   "Render Maps"
         Enabled         =   0   'False
         Height          =   285
         Left            =   120
         TabIndex        =   28
         Top             =   540
         Width           =   1215
      End
      Begin VB.CheckBox chkSmooth 
         Caption         =   "Smooth Rough/Shade Maps"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   1440
         TabIndex        =   27
         Top             =   550
         Value           =   1  'Checked
         Width           =   2655
      End
      Begin MSComctlLib.ProgressBar PB 
         Height          =   180
         Left            =   45
         TabIndex        =   29
         Top             =   920
         Width           =   4110
         _ExtentX        =   7250
         _ExtentY        =   318
         _Version        =   393216
         BorderStyle     =   1
         Appearance      =   0
         Scrolling       =   1
      End
      Begin VB.Label Label7 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Or"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   2685
         TabIndex        =   33
         Top             =   195
         Width           =   195
      End
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Render Maps As"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   210
         Left            =   465
         TabIndex        =   30
         Top             =   195
         Width           =   1365
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private LowerMapOK As Boolean
Private UpperMapOK As Boolean

Private Sub Form_Load()

    LowerMapOK = False
    UpperMapOK = False
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    On Local Error Resume Next
    
    Call HeightMap_Cleanup

End Sub

Private Sub cmdOpenHeightmap_Click()
    On Local Error Resume Next
    
    picCont.SetFocus
    CD.Filter = "Graphic Files (*bmp, *tga)|*bmp;*tga"
    CD.InitDir = App.Path
    CD.ShowOpen

    If (CD.Filename <> vbNullString) Then
        txtHeightMapFilename.Text = CD.FileTitle
        
        Call HeightMap_PreLoad(CD.Filename)
        Canvas.Width = HeightMap_GetExtent()
        Canvas.Height = HeightMap_GetExtent()
        DoEvents
        
        Call HeightMap_FinalizeLoad(Canvas.HDC)
        Canvas.Picture = Canvas.Image
        Canvas.Refresh
        Call SetupScrollBars
        
        cmdOpenL.Enabled = True
        cmdOpenU.Enabled = True
        txtLowerF.Enabled = True
        txtUpperF.Enabled = True
    End If

End Sub

Private Sub cmdOpenL_Click()

    picCont.SetFocus
    CD.Filter = "Graphic Files (*bmp, *tga)|*bmp;*tga"
    CD.InitDir = App.Path
    CD.ShowOpen

    If (CD.Filename <> vbNullString) Then
        txtLowerF.Text = CD.FileTitle
        LowerMapOK = True
    End If
    
    If (LowerMapOK And UpperMapOK) Then
        cmdRender.Enabled = True
    End If
    
End Sub

Private Sub cmdOpenU_Click()

    picCont.SetFocus
    CD.Filter = "Graphic Files (*bmp, *tga)|*bmp;*tga"
    CD.InitDir = App.Path
    CD.ShowOpen

    If (CD.Filename <> vbNullString) Then
        txtUpperF.Text = CD.FileTitle
        UpperMapOK = True
    End If
    
    If (LowerMapOK And UpperMapOK) Then
        cmdRender.Enabled = True
    End If
    
End Sub

Private Sub cmdRender_Click()

    Dim LightParam As LightParamerters
    LightParam.Positon.X = CSng(Val(txtLPos(0)))
    LightParam.Positon.Y = CSng(Val(txtLPos(1)))
    LightParam.Positon.Z = CSng(Val(txtLPos(2)))
    LightParam.Intensity = CSng(Val(txtLIntesity))
    
    Dim ExportType As Integer
    If (optExportType(0).Value) Then
        ExportType = 0
    Else
        ExportType = 1
    End If
    
    If (chkSmooth.Value) Then
        Call HeightMap_CreateShadeMap(LightParam, 1, ExportType)
    Else
        Call HeightMap_CreateShadeMap(LightParam, 0, ExportType)
    End If
    PB.Value = 25
    
    If (chkSmooth.Value) Then
        Call HeightMap_CreateRoughMap(1, ExportType)
    Else
        Call HeightMap_CreateRoughMap(0, ExportType)
    End If
    PB.Value = 50
    
    Call HeightMap_RenderMap(txtLowerF, txtUpperF, 80, 110, ExportType)
    PB.Value = 75
 
    Call HeightMap_BlendWithShadeMap(0.85, ExportType)
    PB.Value = 100

End Sub

Private Sub SetupScrollBars()

    If ((Canvas.ScaleWidth + 16) > picCont.ScaleWidth) Then
        HScroll.Enabled = True
        HScroll.Min = -8
        HScroll.Max = (Canvas.ScaleWidth / 2) - 8
        HScroll.SmallChange = (Canvas.ScaleWidth + 16) / 6
        HScroll.LargeChange = (Canvas.ScaleWidth + 16) / 4
    End If
    
    If ((Canvas.ScaleHeight + 16) > picCont.ScaleHeight) Then
        VScroll.Enabled = True
        VScroll.Min = -8
        VScroll.Max = (Canvas.ScaleHeight / 2) - 8
        VScroll.SmallChange = (Canvas.ScaleHeight + 16) / 6
        VScroll.LargeChange = (Canvas.ScaleHeight + 16) / 4
    End If

End Sub

Private Sub HScroll_Change()
    
    Canvas.Left = -HScroll.Value
    
End Sub

Private Sub HScroll_Scroll()

    Call HScroll_Change

End Sub

Private Sub VScroll_Change()
    
    Canvas.Top = -VScroll.Value
    
End Sub

Private Sub VScroll_Scroll()

    Call VScroll_Change

End Sub
