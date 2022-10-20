object FormDice: TFormDice
  Left = 331
  Top = 194
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = #1048#1075#1088#1072#1083#1100#1085#1099#1077' '#1082#1091#1073#1080#1082#1080
  ClientHeight = 49
  ClientWidth = 226
  Color = clWhite
  TransparentColorValue = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 154
    Top = 1
    Width = 63
    Height = 20
    Caption = #1042#1099#1087#1072#1083#1086':'
  end
  object res: TLabel
    Left = 149
    Top = 23
    Width = 72
    Height = 20
    Alignment = taCenter
    AutoSize = False
    Caption = ' - '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -20
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SingleDice: TButton
    Left = 0
    Top = 0
    Width = 145
    Height = 25
    Caption = #1041#1088#1086#1089#1080#1090#1100' '#1082#1091#1073#1080#1082
    TabOrder = 0
    OnClick = SingleDiceClick
  end
  object TwoDice: TButton
    Left = 0
    Top = 25
    Width = 145
    Height = 25
    Caption = #1041#1088#1086#1089#1080#1090#1100' 2 '#1082#1091#1073#1080#1082#1072
    TabOrder = 1
    OnClick = TwoDiceClick
  end
  object PopupMenu1: TPopupMenu
    Left = 72
    Top = 16
    object N6: TMenuItem
      Caption = '6'
      Checked = True
      OnClick = N6Click
    end
    object N10: TMenuItem
      Caption = '10'
      OnClick = N10Click
    end
    object N20: TMenuItem
      Caption = '20'
      OnClick = N20Click
    end
    object N100: TMenuItem
      Caption = '100'
      OnClick = N100Click
    end
  end
end
