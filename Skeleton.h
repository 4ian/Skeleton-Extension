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

#ifndef SKELETON_H
#define SKELETON_H

#include <string>
#include <vector>

#include "Bone.h"
#include "SkeletonAnimator.h"
#include "ImageManager.h"

class wxBufferedPaintDC;

class TiXmlElement;

/**
Sk namespace contains all stuff related to the skeleton engine (base skeleton, bones, animations...).
 */
namespace Sk
{

class Bone;

class Skeleton
{
    friend class Bone;

    public:
        Skeleton();
        Skeleton(const Skeleton &other);
        ~Skeleton();

        void Draw(sf::RenderTarget &target, sf::Vector2f offset, Bone::DrawType);
        #ifdef GD_IDE_ONLY
        void DrawWx(wxBufferedPaintDC &dc, sf::Vector2f offset, Bone *selectedBone);
        #endif

        Bone* CreateBone(const std::string &name);
        void DestroyBone(Bone *bone);

        void RegisterBone(Bone *bone);
        void UnRegisterBone(Bone *bone);

        void SortBones();

        Bone* GetRootBone();

        Anim::SkeletonAnimator& GetAnimator() {return m_skeAnim;};
        void ApplyAnimationToBones();

        Res::SkImageManager& GetImageManager() {return m_imageMan;};
        void ExposeResources();
        void LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr);

        bool IsNameUsed(const std::string &name);

        Bone* GetBone(const std::string &name);
        const std::vector<Bone*>& GetBones() const {return m_bones;};

        void Save(TiXmlElement &elem);
        void Load(const TiXmlElement &elem);

        void EnableAnimationSystem(bool enable);

    protected:
    private:
        Bone *m_rootBone;
        std::vector<Bone*> m_bones;

        bool m_skeAnimEnabled;
        Anim::SkeletonAnimator m_skeAnim;

        Res::SkImageManager m_imageMan;
};

struct ZOrderFunctor
{
    friend class Bone;

    bool operator() (Bone *left, Bone *right) {return (left->m_zorder < right->m_zorder);};
};

}

#endif // SKELETON_H
