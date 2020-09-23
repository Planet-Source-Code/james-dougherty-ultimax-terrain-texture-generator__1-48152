Attribute VB_Name = "UltimaXTTG_API"
Option Explicit

Public Type Vector3
    X As Single
    Y As Single
    Z As Single
End Type

Public Type LightParamerters
    Positon As Vector3
    Intensity As Single
End Type
Public g_LightParamters As LightParamerters

Public Declare Sub HeightMap_PreLoad Lib "UltimaXTTG.dll" (ByVal Filename As String)
Public Declare Sub HeightMap_FinalizeLoad Lib "UltimaXTTG.dll" (ByVal HDC As Long)
Public Declare Function HeightMap_GetExtent Lib "UltimaXTTG.dll" () As Integer
Public Declare Sub HeightMap_CreateRoughMap Lib "UltimaXTTG.dll" (ByVal SmoothIterations As Integer, ByVal ExportExtension As Integer)
Public Declare Sub HeightMap_CreateShadeMap Lib "UltimaXTTG.dll" (ByRef LightParam As LightParamerters, ByVal SmoothIterations As Integer, ByVal ExportExtension As Integer)
Public Declare Sub HeightMap_RenderMap Lib "UltimaXTTG.dll" (ByVal LowerAltitudeMap As String, ByVal HigherAltitudeMap As String, ByVal MaxLowerAltitude As Integer, ByVal MaxHeightAltitude As Integer, ByVal ExportExtension As Integer)
Public Declare Sub HeightMap_BlendWithShadeMap Lib "UltimaXTTG.dll" (ByVal Amount As Single, ByVal ExportExtension As Integer)
Public Declare Sub HeightMap_Cleanup Lib "UltimaXTTG.dll" ()
