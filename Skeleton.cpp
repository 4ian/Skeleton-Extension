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

#ifdef GD_IDE_ONLY
#include <wx/dcbuffer.h>
#endif

#include "Skeleton.h"
#include "GDL/tinyxml/tinyxml.h"

namespace Sk
{

Skeleton::Skeleton() : m_rootBone(new Bone("root", this)), m_skeAnimEnabled(true), m_imageMan()
{
    RegisterBone(m_rootBone);
}

Skeleton::Skeleton(const Skeleton &other)
{
    m_bones.clear();

    m_rootBone = new Bone(*other.m_rootBone);
    m_rootBone->ResetOwner(this);

    m_skeAnim = other.m_skeAnim;
    m_skeAnimEnabled = other.m_skeAnimEnabled;
    m_imageMan = Res::SkImageManager();

    //m_root->Update();
}

Skeleton::~Skeleton()
{
    //dtor
}

void Skeleton::Draw(sf::RenderTarget &target, sf::Vector2f offset, Bone::DrawType type)
{
    for(unsigned int a = 0; a < m_bones.size(); a++)
    {
        m_bones.at(a)->Draw(target, offset, type);
    }
}

#ifdef GD_IDE_ONLY

void Skeleton::DrawWx(wxBufferedPaintDC &dc, sf::Vector2f offset, Bone *selectedBone)
{
    for(unsigned int a = 0; a < m_bones.size(); a++)
    {
        m_bones.at(a)->DrawWx(dc, offset, (m_bones.at(a) == selectedBone));
    }
}

#endif

Bone* Skeleton::CreateBone(const std::string &name)
{
    Bone *newbone = new Bone(name, this);
    RegisterBone(newbone);

    return newbone;
}

void Skeleton::DestroyBone(Bone *bone)
{
    for(unsigned int a = 0; a < bone->GetChildrenBones().size(); a++)
    {
        DestroyBone(bone->GetChildrenBones().at(a));
    }
    UnRegisterBone(bone);
    delete bone;
}

void Skeleton::RegisterBone(Bone *bone)
{
    m_bones.push_back(bone);

    SortBones();
}

void Skeleton::UnRegisterBone(Bone *bone)
{
    std::vector<Bone*>::iterator it = std::find(m_bones.begin(), m_bones.end(), bone);

    if(it == m_bones.end())
        return;

    m_bones.erase(it);
}

Bone* Skeleton::GetRootBone()
{
    return m_rootBone;
}

bool Skeleton::IsNameUsed(const std::string &name)
{
    for(std::vector<Bone*>::iterator it = m_bones.begin(); it != m_bones.end(); it++)
    {
        if((*it)->GetName() == name)
            return true;
    }

    return false;
}

void Skeleton::SortBones()
{
    ZOrderFunctor functor;
    std::sort(m_bones.begin(), m_bones.end(), functor);
}

void Skeleton::ApplyAnimationToBones()
{
    if(!m_skeAnimEnabled)
        return;

    m_skeAnim.ApplyToSkeleton(m_bones, m_imageMan);
    m_rootBone->Update();
}

void Skeleton::ExposeResources()
{
    for(unsigned int a = 0; a < m_bones.size(); a++)
    {
        m_imageMan.ExposeImage(m_bones.at(a)->GetTextureName());
    }

    m_skeAnim.ExposeResources(m_imageMan);
}

void Skeleton::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr)
{
    m_imageMan.LoadResources(scene, imageMgr);

    for(unsigned int a = 0; a < m_bones.size(); a++)
    {
        m_bones[a]->LoadTexture(m_imageMan);
    }
}

void Skeleton::Save(TiXmlElement &elem)
{
    TiXmlElement *verEle = new TiXmlElement("Version");
    verEle->SetAttribute("version", GetFileVersion());
    elem.LinkEndChild(verEle);

    GetRootBone()->SaveBone(elem);

    TiXmlElement *animationsElem = new TiXmlElement("Animations");
    elem.LinkEndChild(animationsElem);
    GetAnimator().SaveToXml(animationsElem);
}

void Skeleton::Load(const TiXmlElement &elem)
{
    int version = 0;
    TiXmlElement *verEle = const_cast<TiXmlElement*>(elem.FirstChildElement("Version"));
    if(verEle)
    {
        verEle->QueryIntAttribute("version", &version);
    }

    TiXmlElement *boneElem = const_cast<TiXmlElement*>(elem.FirstChildElement("Bone"));
    if(boneElem)
    {
        GetRootBone()->LoadBone(*boneElem);
    }

    TiXmlElement *animationsElem = const_cast<TiXmlElement*>(elem.FirstChildElement("Animations"));
    if(animationsElem)
    {
        GetAnimator().LoadFromXml(animationsElem, version);
    }
}

Bone* Skeleton::GetBone(const std::string &name)
{
    for(unsigned int a = 0; a < m_bones.size(); a++)
    {
        if(m_bones.at(a)->GetName() == name)
            return m_bones.at(a);
    }

    return NULL;
}

void Skeleton::EnableAnimationSystem(bool enable)
{
    if(enable)
    {
        m_skeAnim.Reset();
    }
    else
    {
        m_skeAnim.SetCurrentAnimationName("Initial");
        m_skeAnim.Reset();
        ApplyAnimationToBones();
    }
    m_skeAnimEnabled = enable;
}

}
