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

#include <SFML/Graphics.hpp>
#include "GDL/Object.h"

#include "GDL/ImageManager.h"
#include "GDL/tinyxml/tinyxml.h"
#include "GDL/Position.h"
#include "GDL/CommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/IDE/ArbitraryResourceWorker.h"
#include "GDL/IDE/MainEditorCommand.h"
#include "SkeletonObjectEditor.h"
#endif

#include "SkeletonObject.h"

SkeletonObject::SkeletonObject(std::string name_) :
Object(name_), skeleton()
{

}

SkeletonObject::~SkeletonObject()
{

}

void SkeletonObject::Init(const SkeletonObject &other)
{
    skeleton = Sk::Skeleton(other.skeleton);
}

SkeletonObject::SkeletonObject(const SkeletonObject &other) : Object(other)
{
    Init(other);
}

SkeletonObject& SkeletonObject::operator=(const SkeletonObject &other)
{
    Init(other);
    return *this;
}

void SkeletonObject::LoadFromXml(const TiXmlElement * elem)
{
    skeleton.Load(*elem);
}

#if defined(GD_IDE_ONLY)
void SkeletonObject::SaveToXml(TiXmlElement * elem)
{
    skeleton.Save(*elem);
}
#endif

bool SkeletonObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    skeleton.GetRoot()->LoadTexture(imageMgr);
    skeleton.GetAnimator().Reset();

    return true;
}

bool SkeletonObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    skeleton.GetRoot()->LoadTexture(imageMgr);
    skeleton.GetAnimator().Reset();

    return true;
}

bool SkeletonObject::Draw( sf::RenderTarget& renderTarget )
{
    skeleton.Draw(renderTarget, sf::Vector2f(GetX(), GetY()), Sk::Bone::Sprites);

    return true;
}


#if defined(GD_IDE_ONLY)
/**
 * Render object at edittime
 */
bool SkeletonObject::DrawEdittime( sf::RenderTarget& renderTarget )
{
    skeleton.Draw(renderTarget, sf::Vector2f(GetX(), GetY()), Sk::Bone::Sprites);

    return true;
}

wxPanel * SkeletonObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void SkeletonObject::ExposeResources(gd::ArbitraryResourceWorker & worker)
{

}

bool SkeletonObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Skeleton24.png", wxBITMAP_TYPE_ANY);
    return true;
}

void SkeletonObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    SkeletonObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();
}

void SkeletonObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
}

bool SkeletonObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    return true;
}

unsigned int SkeletonObject::GetNumberOfProperties() const
{
    return 0;
}
#endif

void SkeletonObject::OnPositionChanged()
{

}

void SkeletonObject::UpdateTime(float time)
{
    skeleton.GetAnimator().UpdateTime(time);
    skeleton.ApplyAnimationToBones();
}

float SkeletonObject::GetDrawableX() const
{
    return GetX();
}

float SkeletonObject::GetDrawableY() const
{
    return GetY();
}

float SkeletonObject::GetWidth() const
{
    return 32;
}

float SkeletonObject::GetHeight() const
{
    return 32;
}

float SkeletonObject::GetCenterX() const
{
    return 16;
}

float SkeletonObject::GetCenterY() const
{
    return 16;
}

Sk::Skeleton SkeletonObject::GetSkeleton()
{
    return skeleton;
}

void SkeletonObject::SetSkeleton(Sk::Skeleton _ske)
{
    skeleton = Sk::Skeleton(_ske);
}

void DestroySkeletonObject(Object * object)
{
    delete object;
}

Object * CreateSkeletonObject(std::string name)
{
    return new SkeletonObject(name);
}
