object InventoryForm: TInventoryForm
  Left = 339
  Top = 202
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = #1053#1086#1074#1099#1081' '#1087#1088#1077#1076#1084#1077#1090
  ClientHeight = 242
  ClientWidth = 254
  Color = clBtnFace
  Constraints.MaxHeight = 500
  Constraints.MaxWidth = 500
  Constraints.MinHeight = 267
  Constraints.MinWidth = 260
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  DesignSize = (
    254
    242)
  PixelsPerInch = 96
  TextHeight = 20
  object Name: TEdit
    Left = 0
    Top = 0
    Width = 255
    Height = 28
    Anchors = [akLeft, akTop, akRight]
    MaxLength = 63
    TabOrder = 0
    Text = 'Name'
    ExplicitWidth = 253
  end
  object Descript: TMemo
    Left = 0
    Top = 112
    Width = 254
    Height = 102
    Hint = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086#1077' '#1086#1087#1080#1089#1072#1085#1080#1077
    Align = alCustom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Descript')
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    ExplicitWidth = 252
    ExplicitHeight = 90
  end
  object HasWeight: TCheckBox
    Left = 8
    Top = 40
    Width = 244
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
    ExplicitWidth = 242
  end
  object Button1: TButton
    Left = 0
    Top = 217
    Width = 91
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 6
    ExplicitTop = 205
    ExplicitWidth = 89
  end
  object Button2: TButton
    Left = 165
    Top = 217
    Width = 89
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 5
    ExplicitLeft = 163
    ExplicitTop = 205
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
  object Estimated: TCheckBox
    Left = 8
    Top = 88
    Width = 129
    Height = 17
    Caption = #1048#1089#1095#1080#1089#1083#1103#1077#1084#1099#1081
    TabOrder = 3
    OnClick = EstimatedClick
  end
  object Kolvo: TCSpinEdit
    Left = 184
    Top = 76
    Width = 60
    Height = 30
    TabOrder = 7
    OnChange = KolvoChange
  end
end
