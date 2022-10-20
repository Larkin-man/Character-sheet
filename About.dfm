object AboutBox: TAboutBox
  Left = 225
  Top = 138
  BorderStyle = bsDialog
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  ClientHeight = 474
  ClientWidth = 504
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 20
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 489
    Height = 433
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 16
      Top = 2
      Width = 131
      Height = 32
      Caption = 'Game Board'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Palatino Linotype'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Version: TLabel
      Left = 392
      Top = 8
      Width = 74
      Height = 22
      Caption = 'Version 1.1'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Palatino Linotype'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object RichEdit1: TRichEdit
      Left = 8
      Top = 40
      Width = 473
      Height = 385
      Lines.Strings = (
        'RichEdit1')
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object OKButton: TButton
    Left = 215
    Top = 444
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
end
