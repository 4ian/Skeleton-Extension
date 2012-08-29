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

#ifndef SkeletonObject_H
#define SkeletonObject_H

#include "GDL/Object.h"

#if defined(GD_IDE_ONLY)
namespace gd {class ArbitraryResourceWorker;}
namespace gd {class Project;}
namespace gd {class MainFrameWrapper;}
#endif

class ImageManager;
class RuntimeScene;
class Object;
class Polygon2d;
class ImageManager;
class InitialPosition;

#if defined(GD_IDE_ONLY)
namespace sf
{
    class Texture;
    class Sprite;
};
class wxBitmap;
class Game;
class wxWindow;
#endif

namespace Sk
{
    class Skeleton;
}

class GD_EXTENSION_API SkeletonObject : public Object
{
    public :

        SkeletonObject(std::string name_);
        virtual ~SkeletonObject();

        SkeletonObject(const SkeletonObject &other);
        SkeletonObject& operator=(const SkeletonObject &other);

        virtual Object* Clone() const;

        virtual bool LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr );
        virtual bool LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr );
        virtual bool InitializeFromInitialPosition(const InitialPosition & position) {return true;}

        virtual bool Draw(sf::RenderTarget & renderTarget);

        #if defined(GD_IDE_ONLY)
        virtual bool DrawEdittime(sf::RenderTarget & renderTarget);
        virtual void ExposeResources(gd::ArbitraryResourceWorker & worker);
        virtual bool GenerateThumbnail(const gd::Project & project, wxBitmap & thumbnail);

        virtual wxPanel * CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position );

        virtual void EditObject( wxWindow* parent, Game & game_, gd::MainFrameWrapper & mainEditorCommand_ );

        virtual void GetPropertyForDebugger (unsigned int propertyNb, std::string & name, std::string & value) const;
        virtual bool ChangeProperty(unsigned int propertyNb, std::string newValue);
        virtual unsigned int GetNumberOfProperties() const;
        #endif

        virtual void LoadFromXml(const TiXmlElement * elemScene);
        #if defined(GD_IDE_ONLY)
        virtual void SaveToXml(TiXmlElement * elemScene);
        #endif

        virtual void UpdateTime(float timeElapsed);

        virtual void OnPositionChanged();

        virtual float GetWidth() const;
        virtual float GetHeight() const;

        virtual void SetWidth(float ) {};
        virtual void SetHeight(float ) {};

        virtual float GetDrawableX() const;
        virtual float GetDrawableY() const;

        virtual float GetCenterX() const;
        virtual float GetCenterY() const;

        virtual bool SetAngle(float newAngle) {return false;};
        virtual float GetAngle() const {return 0;};

        virtual std::vector<Polygon2d> GetHitBoxes() const;

        Sk::Skeleton GetSkeleton();
        void SetSkeleton(Sk::Skeleton _ske);

        void Play();
        void Pause();
        void Stop();

        void SetSpeedRatio(float ratio);

        bool IsPlaying() const;
        bool IsPausing() const;
        bool IsStopped() const;

        float GetSpeedRatio() const;

        void SetAnimation(const std::string &anim);
        const std::string& GetAnimation() const;

    protected:
        void Init(const SkeletonObject &other);

    private:
        Sk::Skeleton *skeleton;
};

void DestroySkeletonObject(Object * object);
Object * CreateSkeletonObject(std::string name);

#endif // SkeletonObject_H
