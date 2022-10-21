object NewItemForm: TNewItemForm
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1053#1086#1074#1099#1081' '#1087#1088#1077#1076#1084#1077#1090
  ClientHeight = 244
  ClientWidth = 256
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  DesignSize = (
    256
    244)
  PixelsPerInch = 96
  TextHeight = 19
  object Descript: TMemo
    Left = 0
    Top = 112
    Width = 256
    Height = 104
    Hint = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086#1077' '#1086#1087#1080#1089#1072#1085#1080#1077
    Align = alCustom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Descript')
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    ExplicitWidth = 254
    ExplicitHeight = 102
  end
  object CancelBtn: TButton
    Left = 167
    Top = 219
    Width = 89
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 8
    ExplicitLeft = 165
    ExplicitTop = 217
  end
  object ButtonAdd: TButton
    Left = 0
    Top = 219
    Width = 93
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 7
    ExplicitTop = 217
    ExplicitWidth = 91
  end
  object Estimated: TCheckBox
    Left = 8
    Top = 88
    Width = 129
    Height = 17
    Caption = #1048#1089#1095#1080#1089#1083#1103#1077#1084#1099#1081
    TabOrder = 3
    OnClick = EstimatedClick
  end
  object Hasatstart: TCheckBox
    Left = 8
    Top = 64
    Width = 177
    Height = 17
    Caption = #1045#1089#1090#1100' '#1074' '#1085#1072#1095#1072#1083#1077' '#1080#1075#1088#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object HasWeight: TCheckBox
    Left = 8
    Top = 40
    Width = 246
    Height = 17
    Anchors = [akLeft, akTop, akRight]
    Caption = #1047#1072#1085#1080#1084#1072#1077#1090' '#1084#1077#1089#1090#1086' '#1074' '#1080#1085#1074#1077#1085#1090#1072#1088#1077
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 1
    ExplicitWidth = 244
  end
  object Name: TEdit
    Left = -1
    Top = 0
    Width = 257
    Height = 28
    Anchors = [akLeft, akTop, akRight]
    MaxLength = 63
    TabOrder = 0
    Text = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object Kolvo: TEdit
    Left = 176
    Top = 83
    Width = 51
    Height = 27
    NumbersOnly = True
    TabOrder = 4
    Text = '0'
  end
  object UpDown1: TUpDown
    Left = 227
    Top = 83
    Width = 18
    Height = 27
    Associate = Kolvo
    TabOrder = 5
    OnChanging = UpDown1Changing
  end
end
