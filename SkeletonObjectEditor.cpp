/*
Copyright (C) 2012 Victor Levasseur

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
  */

#if defined(GD_IDE_ONLY)

#include "SkeletonObjectEditor.h"

//(*InternalHeaders(SkeletonObjectEditor)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/dcbuffer.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>

#include "GDL/Game.h"
#include "SkeletonObject.h"
#include "GDL/IDE/MainEditorCommand.h"
#include "GDCore/IDE/CommonBitmapManager.h"
#include "GDL/CommonTools.h"
#include "GDL/IDE/Dialogs/ResourcesEditor.h"

//(*IdInit(SkeletonObjectEditor)
const long SkeletonObjectEditor::ID_TOGGLEBUTTON1 = wxNewId();
const long SkeletonObjectEditor::ID_TOGGLEBUTTON2 = wxNewId();
const long SkeletonObjectEditor::ID_CHOICE1 = wxNewId();
const long SkeletonObjectEditor::ID_BITMAPBUTTON2 = wxNewId();
const long SkeletonObjectEditor::ID_BITMAPBUTTON3 = wxNewId();
const long SkeletonObjectEditor::ID_PANEL3 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT9 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL8 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT10 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON9 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON10 = wxNewId();
const long SkeletonObjectEditor::ID_PANEL1 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT1 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT2 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT3 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT4 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL3 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT6 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL5 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT7 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL7 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT5 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL4 = wxNewId();
const long SkeletonObjectEditor::ID_BITMAPBUTTON1 = wxNewId();
const long SkeletonObjectEditor::ID_STATICTEXT8 = wxNewId();
const long SkeletonObjectEditor::ID_TEXTCTRL6 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON5 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON7 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON8 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON2 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON4 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON6 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON1 = wxNewId();
const long SkeletonObjectEditor::ID_BUTTON3 = wxNewId();
const long SkeletonObjectEditor::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SkeletonObjectEditor,wxDialog)
	//(*EventTable(SkeletonObjectEditor)
	//*)
END_EVENT_TABLE()

SkeletonObjectEditor::SkeletonObjectEditor( wxWindow* parent, Game & game_, SkeletonObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_),
skeleton(object.GetSkeleton()),
mode(0)
{
	//(*Initialize(SkeletonObjectEditor)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer15;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer14;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer13;
	wxFlexGridSizer* FlexGridSizer12;
	wxFlexGridSizer* FlexGridSizer6;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;

	Create(parent, wxID_ANY, _("Editer le squelette"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	SetClientSize(wxSize(752,489));
	FlexGridSizer3 = new wxFlexGridSizer(1, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableRow(0);
	Core = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5->AddGrowableCol(0);
	FlexGridSizer5->AddGrowableRow(1);
	FlexGridSizer11 = new wxFlexGridSizer(0, 5, 0, 0);
	ToggleButton1 = new wxToggleButton(Core, ID_TOGGLEBUTTON1, _("Edition des os"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	ToggleButton1->SetValue(true);
	FlexGridSizer11->Add(ToggleButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ToggleButton2 = new wxToggleButton(Core, ID_TOGGLEBUTTON2, _("Animation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	FlexGridSizer11->Add(ToggleButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AnimationCombobox = new wxChoice(Core, ID_CHOICE1, wxDefaultPosition, wxSize(167,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	FlexGridSizer11->Add(AnimationCombobox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton2 = new wxBitmapButton(Core, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("res/addicon.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	BitmapButton2->SetDefault();
	FlexGridSizer11->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton3 = new wxBitmapButton(Core, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("res/deleteicon.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	BitmapButton3->SetDefault();
	FlexGridSizer11->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer12 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer12->AddGrowableCol(0);
	Panel2 = new wxPanel(Core, ID_PANEL3, wxDefaultPosition, wxSize(662,48), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer12->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer14 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText9 = new wxStaticText(Core, ID_STATICTEXT9, _("Periode :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer14->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	periodTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL8, _("0"), wxDefaultPosition, wxSize(39,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FlexGridSizer14->Add(periodTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(Core, ID_STATICTEXT10, _("s"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer14->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer13->Add(FlexGridSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer15 = new wxFlexGridSizer(0, 2, 0, 0);
	Button4 = new wxButton(Core, ID_BUTTON9, _("Zoom +"), wxDefaultPosition, wxSize(64,23), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	FlexGridSizer15->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button5 = new wxButton(Core, ID_BUTTON10, _("-"), wxDefaultPosition, wxSize(22,23), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer15->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13->Add(FlexGridSizer15, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer12->Add(FlexGridSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer12, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer6->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(1, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Core, _("Apercu"));
	Panel1 = new wxPanel(Core, ID_PANEL1, wxDefaultPosition, wxSize(453,373), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Core, _("Os selectionne"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(Core, ID_STATICTEXT1, _("Nom :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	nameTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer4->Add(nameTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Core, ID_STATICTEXT2, _("Angle :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	angleTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer4->Add(angleTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Core, ID_STATICTEXT3, _("relatif a l\'os parent."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_ITALIC,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Core, ID_STATICTEXT4, _("Longueur :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer4->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	lengthTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer4->Add(lengthTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Core, ID_STATICTEXT6, _("Décalage :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer4->Add(StaticText6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9 = new wxFlexGridSizer(0, 3, 0, 0);
	offsetXTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxSize(62,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer9->Add(offsetXTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Core, ID_STATICTEXT7, _(";"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer9->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	offsetYTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(63,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	FlexGridSizer9->Add(offsetYTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText5 = new wxStaticText(Core, ID_STATICTEXT5, _("Image :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer8->AddGrowableCol(0);
	imageTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer8->Add(imageTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BitmapButton1 = new wxBitmapButton(Core, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res/addfromimagebanque.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	FlexGridSizer8->Add(BitmapButton1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText8 = new wxStaticText(Core, ID_STATICTEXT8, _("Plan :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer4->Add(StaticText8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer10->AddGrowableCol(0);
	zOrderTextCtrl = new wxTextCtrl(Core, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	FlexGridSizer10->Add(zOrderTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Core, ID_BUTTON5, _("Appliquer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer4->Add(Button1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	createKeyFrameBt = new wxButton(Core, ID_BUTTON7, _("Frame cle"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	createKeyFrameBt->SetToolTip(_("Crée une frame clé pour l\'os sélectionné à sa position actuelle"));
	BoxSizer1->Add(createKeyFrameBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	removeKeyFrameBt = new wxButton(Core, ID_BUTTON8, _("Enlever f.clé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer1->Add(removeKeyFrameBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	addChildBoneBt = new wxButton(Core, ID_BUTTON2, _("Ajouter un os enfant"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(addChildBoneBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	deleteBoneBt = new wxButton(Core, ID_BUTTON4, _("Supprimer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer2->Add(deleteBoneBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 4, 0, 0);
	Button3 = new wxButton(Core, ID_BUTTON6, _("Banque d\'image"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer7->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ValidateButton = new wxButton(Core, ID_BUTTON1, _("Valider"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer7->Add(ValidateButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Core, ID_BUTTON3, _("Annuler"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer7->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer7, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Core->SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(Core);
	FlexGridSizer6->SetSizeHints(Core);
	FlexGridSizer3->Add(Core, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer3);
	FlexGridSizer3->SetSizeHints(this);
	Center();

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnToggleButton2Toggle);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SkeletonObjectEditor::OnAnimationComboboxSelect);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnBitmapButton2Click);
	Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2Paint,0,this);
	Panel2->Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2EraseBackground,0,this);
	Panel2->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2LeftDown,0,this);
	Panel2->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2RightDown,0,this);
	Panel2->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2RightUp,0,this);
	Panel2->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel2MouseWheel,0,this);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SkeletonObjectEditor::OnTextCtrl1TextEnter);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SkeletonObjectEditor::OnTextCtrl1TextEnter);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnButton4Click);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnButton5Click);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1Paint,0,this);
	Panel1->Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1EraseBackground,0,this);
	Panel1->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1LeftDown,0,this);
	Panel1->Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1RightDown,0,this);
	Panel1->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1RightUp,0,this);
	Panel1->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SkeletonObjectEditor::OnPanel1MouseMove,0,this);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnnameTextCtrlText);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OncreateKeyFrameBtClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnremoveKeyFrameBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnaddChildBoneBtClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OndeleteBoneBtClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnButton3Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnValidateButtonClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkeletonObjectEditor::OnButton2Click);
	//*)

	resourcesEditor = new ResourcesEditor( this, game, mainEditorCommand );
    resourcesEditor->Refresh();

	m_mgr.SetManagedWindow( this );
    m_mgr.AddPane( Core, wxAuiPaneInfo().Name( wxT( "Core" ) ).Center().CaptionVisible(false) );
    m_mgr.AddPane( resourcesEditor, wxAuiPaneInfo().Name( wxT( "EI" ) ).Left().Caption( _T( "Editeur de la banque d'images" ) ).MaximizeButton( true ).MinimizeButton( false ).Show(false).MinSize(150, 100) );
    m_mgr.SetFlags( wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_TRANSPARENT_HINT
                    | wxAUI_MGR_TRANSPARENT_DRAG | wxAUI_MGR_HINT_FADE | wxAUI_MGR_NO_VENETIAN_BLINDS_FADE );
    m_mgr.Update();

    offset = sf::Vector2f(20, 20);
    isDragging = false;
    selectedBone = 0;

    timeline_current = 0;
    timeline_currentAnim = 0;
    timeline_offset = 0;
    timeline_scale = 5;

    ToggleMode(0);
    UpdateAnimationsList();

    skeleton.GetRoot()->Update();
}

SkeletonObjectEditor::~SkeletonObjectEditor()
{
    m_mgr.UnInit();
	//(*Destroy(SkeletonObjectEditor)
	//*)
}

void SkeletonObjectEditor::OnValidateButtonClick(wxCommandEvent& event)
{
    skeleton.GetAnimator().SetCurrentAnimation("Initial");
    skeleton.GetAnimator().Reset();
    skeleton.ApplyAnimationToBones();
    object.SetSkeleton(skeleton);

    EndModal(1);
}

void SkeletonObjectEditor::OnButton2Click(wxCommandEvent& event)
{
    EndModal(0);
}

void SkeletonObjectEditor::OnButton1Click(wxCommandEvent& event)
{

}

void SkeletonObjectEditor::OnPanel1Paint(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(Panel1);
    wxSize panelSize = Panel1->GetSize();

    //Draw background
    dc.SetBrush(gd::CommonBitmapManager::GetInstance()->transparentBg);
    dc.DrawRectangle(0,0, panelSize.GetWidth(), panelSize.GetHeight());

    skeleton.DrawWx(dc, offset);
}

void SkeletonObjectEditor::OnPanel1LeftDown(wxMouseEvent& event)
{
    skeleton.GetRoot()->UnselectAllChilds();
    selectedBone = 0;

    sf::Vector2f mousePos(event.GetPosition().x, event.GetPosition().y);

    Bone *searched = FindBoneOnPosition(mousePos, skeleton.GetRoot());

    if(searched)
    {
        selectedBone = searched;
        searched->Select(true);
    }
    else
    {
        selectedBone = 0;
    }

    Panel1->Refresh(); //Refresh
    Panel1->Update(); //Immediately

    Panel2->Refresh();
    Panel2->Update();

    UpdateForSelectedBone();
}

void SkeletonObjectEditor::OnPanel1RightDown(wxMouseEvent& event)
{
    lastPos = sf::Vector2f(event.GetPosition().x, event.GetPosition().y);

    isDragging = true;
}

void SkeletonObjectEditor::OnPanel1RightUp(wxMouseEvent& event)
{
    isDragging = false;
}

void SkeletonObjectEditor::OnPanel1MouseMove(wxMouseEvent& event)
{
    if(isDragging)
    {
        sf::Vector2f newPosDiff = sf::Vector2f(event.GetPosition().x, event.GetPosition().y) - lastPos;

        offset += newPosDiff;

        lastPos = sf::Vector2f(event.GetPosition().x, event.GetPosition().y);

        Panel1->Refresh(); //Refresh
        Panel1->Update(); //Immediately
    }
}

void SkeletonObjectEditor::OnaddChildBoneBtClick(wxCommandEvent& event)
{
    Bone *newBone = skeleton.CreateBone("new bone");
    selectedBone->AddBone(newBone);

    skeleton.GetRoot()->UnselectAllChilds();

    selectedBone = newBone;
    selectedBone->Update();
    selectedBone->Select(true);

    Panel1->Refresh(); //Refresh
    Panel1->Update(); //Immediately

    UpdateForSelectedBone();
}

void SkeletonObjectEditor::OndeleteBoneBtClick(wxCommandEvent& event)
{
    skeleton.GetRoot()->RemoveBone(selectedBone);
    selectedBone = 0;

    skeleton.GetRoot()->UnselectAllChilds();

    Panel1->Refresh(); //Refresh
    Panel1->Update(); //Immediately

    UpdateForSelectedBone();
}

void SkeletonObjectEditor::UpdateForSelectedBone()
{
    if(selectedBone)
    {
        nameTextCtrl->SetValue(wxString(selectedBone->GetName()));
        angleTextCtrl->SetValue(wxString(ToString(selectedBone->GetRotation())));
        lengthTextCtrl->SetValue(wxString(ToString(selectedBone->GetSize())));
        offsetXTextCtrl->SetValue(wxString(ToString(selectedBone->GetOffset().x)));
        offsetYTextCtrl->SetValue(wxString(ToString(selectedBone->GetOffset().y)));
        imageTextCtrl->SetValue(wxString(selectedBone->GetTextureName()));
        zOrderTextCtrl->SetValue(wxString(ToString(selectedBone->GetZOrder())));
    }
    else
    {
        nameTextCtrl->SetValue("");
        angleTextCtrl->SetValue("");
        lengthTextCtrl->SetValue("");
        offsetXTextCtrl->SetValue("");
        offsetYTextCtrl->SetValue("");
        imageTextCtrl->SetValue("");
        zOrderTextCtrl->SetValue("");
    }
}

Bone* SkeletonObjectEditor::FindBoneOnPosition(sf::Vector2f position, Bone *base)
{
    if(base->IsOnPosition(position - offset))
        return base;

    for(unsigned int a = 0; a < base->GetChildrenBones().size(); a++)
    {
        Bone *searched = FindBoneOnPosition(position, base->GetChildrenBones().at(a));
        if(searched)
            return searched;
    }

    return 0;
}

void SkeletonObjectEditor::OnnameTextCtrlText(wxCommandEvent& event)
{
    if(mode == 0)
    {
        if(selectedBone)
        {
            std::string oldname = selectedBone->GetName();

            if(skeleton.BoneNameAlreadyUsed(ToString(nameTextCtrl->GetValue())) && ToString(nameTextCtrl->GetValue()) != oldname)
            {
                wxMessageBox("Un os ayant ce nom existe déjà.\nModifiez le nom et cliquez sur Appliquer.", "Nom de l'os");
                return;
            }

            selectedBone->SetName(ToString(nameTextCtrl->GetValue()));
            skeleton.GetAnimator().NotifyBoneRenamed(oldname, selectedBone->GetName());

            selectedBone->SetRotation(ToFloat(ToString(angleTextCtrl->GetValue())));
            selectedBone->SetSize(ToFloat(ToString(lengthTextCtrl->GetValue())));
            selectedBone->SetTextureName(ToString(imageTextCtrl->GetValue()));
            selectedBone->SetOffset(ToFloat(ToString(offsetXTextCtrl->GetValue())),
                                    ToFloat(ToString(offsetYTextCtrl->GetValue())));
            selectedBone->SetZOrder(ToFloat(ToString(zOrderTextCtrl->GetValue())));

            selectedBone->Update();

            skeleton.GetAnimator().GetAnimation("Initial").SetPeriod(0);
            skeleton.GetAnimator().GetAnimation("Initial").SetKeyFrame(selectedBone->GetName(), AngleKeyFrame, 0, ToFloat(ToString(angleTextCtrl->GetValue())));
        }
    }
    else
    {
        if(selectedBone)
        {
            selectedBone->SetRotation(ToFloat(ToString(angleTextCtrl->GetValue())));
            selectedBone->SetColor(wxColour(255, 0, 0));
            selectedBone->Update();
        }
    }

    Panel1->Refresh(); //Refresh
    Panel1->Update();
}

void SkeletonObjectEditor::ToggleMode(char _mode)
{
    for(unsigned int a = 0; a < skeleton.GetListOfBones().size(); a++)
    {
        skeleton.GetListOfBones().at(a)->UnColorize();
    }

    if(_mode == 0)
    {
        skeleton.GetAnimator().SetCurrentAnimation("Initial");
        skeleton.GetAnimator().Seek(0);

        timeline_currentAnim = 0;

        ToggleButton1->SetValue(true);
        ToggleButton2->SetValue(false);

        nameTextCtrl->Enable(true);
        lengthTextCtrl->Enable(true);
        offsetXTextCtrl->Enable(true);
        offsetYTextCtrl->Enable(true);
        imageTextCtrl->Enable(true);
        BitmapButton1->Enable(true);
        zOrderTextCtrl->Enable(true);
        addChildBoneBt->Enable(true);
        deleteBoneBt->Enable(true);

        BitmapButton2->Enable(false);
        BitmapButton3->Enable(false);
        AnimationCombobox->Enable(false);
    }
    else
    {
        skeleton.GetAnimator().GetAnimation("Initial").SetPeriod(0);
        for(std::vector<Bone*>::const_iterator it = skeleton.GetListOfBones().begin(); it != skeleton.GetListOfBones().end(); it++)
        {
            skeleton.GetAnimator().GetAnimation("Initial").SetKeyFrame((*it)->GetName(), AngleKeyFrame, 0, (*it)->GetRotation());
        }
        skeleton.GetAnimator().Seek(0);

        ToggleButton1->SetValue(false);
        ToggleButton2->SetValue(true);

        nameTextCtrl->Enable(false);
        lengthTextCtrl->Enable(false);
        offsetXTextCtrl->Enable(false);
        offsetYTextCtrl->Enable(false);
        imageTextCtrl->Enable(false);
        BitmapButton1->Enable(false);
        zOrderTextCtrl->Enable(false);
        addChildBoneBt->Enable(false);
        deleteBoneBt->Enable(false);

        BitmapButton2->Enable(true);
        BitmapButton3->Enable(true);
        AnimationCombobox->Enable(true);

        SelectAnimation(ToString(AnimationCombobox->GetString(AnimationCombobox->GetSelection())));
    }
    mode = _mode;

    skeleton.ApplyAnimationToBones();

    Panel1->Refresh();
    Panel1->Update();

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::OnToggleButton1Toggle(wxCommandEvent& event)
{
    ToggleMode(0);
}

void SkeletonObjectEditor::OnToggleButton2Toggle(wxCommandEvent& event)
{
    ToggleMode(1);
}

void SkeletonObjectEditor::OnButton3Click(wxCommandEvent& event)
{
    if ( !m_mgr.GetPane( resourcesEditor ).IsShown() )
        SetSize(GetSize().GetWidth()+150, GetSize().GetHeight());

    m_mgr.GetPane( resourcesEditor ).Show();
    m_mgr.Update();
}

void SkeletonObjectEditor::OnPanel1EraseBackground(wxEraseEvent& event)
{
}

void SkeletonObjectEditor::OnPanel2Paint(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(Panel2);
    wxSize panelSize = Panel2->GetSize();

    dc.SetBrush(wxBrush(wxColour(255, 255, 255)));
    dc.DrawRectangle(0, 0, panelSize.GetWidth(), panelSize.GetHeight());

    if(mode == 0)
        return;

    dc.SetBrush(wxBrush(wxColour(114, 114, 114)));
    dc.DrawRectangle(0, 16, panelSize.GetWidth(), panelSize.GetHeight());

    if(timeline_currentAnim)
    {
        dc.SetBrush(wxBrush(wxColour(160, 160, 160)));
        dc.DrawRectangle(0, 16, GetPositionFromTimeToPixel(timeline_currentAnim->GetPeriod()), panelSize.GetHeight());
    }

    //Each 5s and 10s lines
    for(int a = floor(timeline_offset / 10) - 1; a < floor(timeline_offset / 5) + floor(panelSize.GetWidth() / (timeline_scale * 10)) + 2;a++)
    {
        dc.DrawText(ToString(a * 10), (a * timeline_scale * 10) - (timeline_offset * timeline_scale) - 7, 2);

        dc.SetPen(wxColour(100, 100, 100));

        dc.DrawLine((a * timeline_scale * 10 - 5 * timeline_scale) - (timeline_offset * timeline_scale), 17,
                    (a * timeline_scale * 10 - 5 * timeline_scale) - (timeline_offset * timeline_scale), panelSize.GetHeight() - 1);

        dc.SetPen(wxColour(91, 91, 91));

        dc.DrawLine((a * timeline_scale * 10) - (timeline_offset * timeline_scale), 17,
                    (a * timeline_scale * 10) - (timeline_offset * timeline_scale), panelSize.GetHeight() - 1);
    }

    if(timeline_currentAnim)
    {
        dc.SetPen(wxColour(0, 148, 255));

        std::vector<float> keyFrames = timeline_currentAnim->GetListOfKeyFramesTime();
        for(unsigned int a = 0; a < keyFrames.size(); a++)
        {
            dc.DrawLine(GetPositionFromTimeToPixel(keyFrames.at(a)), 17,
                        GetPositionFromTimeToPixel(keyFrames.at(a)), panelSize.GetHeight() - 1);
        }

        if(selectedBone)
        {
            dc.SetPen(wxColour(0, 255, 255));

            std::vector<float> keyFrames = timeline_currentAnim->GetListOfKeyFramesTime(selectedBone->GetName());
            for(unsigned int a = 0; a < keyFrames.size(); a++)
            {
                dc.DrawLine(GetPositionFromTimeToPixel(keyFrames.at(a)), 17,
                            GetPositionFromTimeToPixel(keyFrames.at(a)), panelSize.GetHeight() - 1);
            }
        }
    }

    dc.SetPen(wxColour(91, 255, 91));

    dc.DrawLine(GetPositionFromTimeToPixel(timeline_current), 17,
                GetPositionFromTimeToPixel(timeline_current), panelSize.GetHeight() - 1);

    dc.DrawText(ToString(timeline_current), GetPositionFromTimeToPixel(timeline_current) + 5, 20);
}

void SkeletonObjectEditor::OnPanel2EraseBackground(wxEraseEvent& event)
{
}

void SkeletonObjectEditor::OnPanel2LeftDown(wxMouseEvent& event)
{
    if(!timeline_currentAnim)
        return;

    float time = GetPositionFromPixelToTime(event.GetX());

    std::vector<float> keyFrames = timeline_currentAnim->GetListOfKeyFramesTime();
    for(unsigned int a = 0; a < keyFrames.size(); a++)
    {
        if(event.GetX() > GetPositionFromTimeToPixel(keyFrames.at(a)) - 4 && event.GetX() < GetPositionFromTimeToPixel(keyFrames.at(a)) + 4)
        {
            time = keyFrames.at(a);
        }
    }

    Seek(time);
}

void SkeletonObjectEditor::OnPanel2MouseWheel(wxMouseEvent& event)
{
//
}

void SkeletonObjectEditor::OnPanel2RightDown(wxMouseEvent& event)
{
    timeline_tmp_dragbegan = event.GetPosition().x;
}

void SkeletonObjectEditor::OnPanel2RightUp(wxMouseEvent& event)
{
    int newPosition = event.GetPosition().x;
    timeline_offset += (newPosition - timeline_tmp_dragbegan) / timeline_scale;

    if(timeline_offset < 0)
        timeline_offset = 0;

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::OnButton4Click(wxCommandEvent& event)
{
    timeline_scale *= 2;

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::OnButton5Click(wxCommandEvent& event)
{
    timeline_scale /= 2;

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::UpdateAnimationsList()
{
    wxString selected = AnimationCombobox->GetString(AnimationCombobox->GetSelection());
    AnimationCombobox->Clear();

    std::vector<std::string> animations = skeleton.GetAnimator().GetListOfAnimations();

    for(unsigned int a = 0; a < animations.size(); a++)
    {
        if(animations.at(a) != "Initial")
            AnimationCombobox->AppendString(animations.at(a).c_str());
    }

    if(AnimationCombobox->FindString(selected, true) != -1)
        AnimationCombobox->Select(AnimationCombobox->FindString(selected, true));
}

void SkeletonObjectEditor::SelectAnimation(const std::string &name)
{
    for(unsigned int a = 0; a < skeleton.GetListOfBones().size(); a++)
    {
        skeleton.GetListOfBones().at(a)->UnColorize();
    }

    if(name == "")
    {
        timeline_currentAnim = 0;
        timeline_offset = 0;
        timeline_current = 0;

        periodTextCtrl->SetValue("0");

        Panel2->Refresh(); //Refresh
        Panel2->Update();

        return;
    }

    timeline_currentAnim = &(skeleton.GetAnimator().GetAnimation(name));
    skeleton.GetAnimator().SetCurrentAnimation(name);
    timeline_offset = 0;
    timeline_current = 0;

    periodTextCtrl->SetValue(ToString(timeline_currentAnim->GetPeriod()).c_str());

    skeleton.ApplyAnimationToBones();

    Panel2->Refresh(); //Refresh
    Panel2->Update();

    if(ToString(AnimationCombobox->GetString(AnimationCombobox->GetSelection())) != name)
    {
        if(AnimationCombobox->FindString(name, true) != -1)
            AnimationCombobox->Select(AnimationCombobox->FindString(name, true));
    }
}

void SkeletonObjectEditor::Seek(float time)
{
    for(unsigned int a = 0; a < skeleton.GetListOfBones().size(); a++)
    {
        skeleton.GetListOfBones().at(a)->UnColorize();
    }

    skeleton.GetAnimator().Seek(time);
    skeleton.ApplyAnimationToBones();
    timeline_current = time;

    for(unsigned int a = 0; a < skeleton.GetListOfBones().size(); a++)
    {
        if(skeleton.GetAnimator().GetAnimation(skeleton.GetAnimator().GetCurrentAnimation()).HasKeyFrame(skeleton.GetListOfBones().at(a)->GetName(), AngleKeyFrame, timeline_current))
        {
            skeleton.GetListOfBones().at(a)->SetColor(wxColour(0, 255, 0));
        }
    }

    Panel2->Refresh(); //Refresh
    Panel2->Update();

    Panel1->Refresh(); //Refresh
    Panel1->Update();
}

int SkeletonObjectEditor::GetPositionFromTimeToPixel(float time)
{
    return (time * timeline_scale) - (timeline_offset * timeline_scale);
}

float SkeletonObjectEditor::GetPositionFromPixelToTime(int pixel)
{
    return (pixel) / timeline_scale + timeline_offset;
}

void SkeletonObjectEditor::OnAnimationComboboxSelect(wxCommandEvent& event)
{
    SelectAnimation(ToString(AnimationCombobox->GetString(AnimationCombobox->GetSelection())));
}

void SkeletonObjectEditor::OnTextCtrl1TextEnter(wxCommandEvent& event)
{
    if(!timeline_currentAnim)
        return;

    timeline_currentAnim->SetPeriod(ToFloat(ToString(periodTextCtrl->GetValue())));

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::OnBitmapButton2Click(wxCommandEvent& event)
{
    //Add an animation
    wxTextEntryDialog dialog(this, _("Nom de l'animation"), _("Nouvelle animation"), "New Animation");
    dialog.ShowModal();

    skeleton.GetAnimator().CreateAnimation(std::string(dialog.GetValue().c_str()), "Initial");
    SelectAnimation(std::string(dialog.GetValue().c_str()));

    UpdateAnimationsList();
}

void SkeletonObjectEditor::OncreateKeyFrameBtClick(wxCommandEvent& event)
{
    if(!timeline_currentAnim || !selectedBone)
        return;

    timeline_currentAnim->SetKeyFrame(selectedBone->GetName(), AngleKeyFrame,  timeline_current, selectedBone->GetRotation());
    selectedBone->SetColor(wxColour(0, 255, 0));

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

void SkeletonObjectEditor::OnremoveKeyFrameBtClick(wxCommandEvent& event)
{
    if(!timeline_currentAnim || !selectedBone)
        return;

    timeline_currentAnim->RemoveKeyFrame(selectedBone->GetName(), AngleKeyFrame, timeline_current);

    Panel2->Refresh(); //Refresh
    Panel2->Update();
}

#endif
