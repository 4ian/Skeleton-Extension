#include "skeletonanimator.h"



#include "GDL/tinyxml/tinyxml.h"
#include "GDL/CommonTools.h"

#include "Bone.h"
#include "interpolationMethods.h"

namespace Sk
{

namespace Anim
{

SkeletonAnimator::SkeletonAnimator() : m_currentAnimation("Initial"), m_isRunning(true), m_isStopped(false), m_speedRatio(1.f)
{
    //ctor
    CreateAnimation("Initial");
}

SkeletonAnimator::~SkeletonAnimator()
{
    //dtor
}

const std::string& SkeletonAnimator::GetCurrentAnimation() const
{
    return m_currentAnimation;
}

void SkeletonAnimator::SetCurrentAnimation(const std::string &animName)
{
    Stop();
    m_currentAnimation = animName;
    GetAnimation(m_currentAnimation).Reset();
    Play();
}

void SkeletonAnimator::CreateAnimation(const std::string &name, const std::string &asACopyOf)
{
    if(asACopyOf != "")
        m_animations[name] = Animation(m_animations[asACopyOf]);
    else
        m_animations[name] = Animation();
}

void SkeletonAnimator::RenameAnimation(const std::string &name, const std::string &newName)
{
    m_animations[newName] = m_animations[name];
    DeleteAnimation(name);
}

void SkeletonAnimator::DeleteAnimation(const std::string &name)
{
    m_animations.erase(name);
}

std::vector<std::string> SkeletonAnimator::GetListOfAnimations() const
{
    std::vector<std::string> animations;

    for(std::map<std::string, Animation>::const_iterator it = m_animations.begin(); it != m_animations.end(); it++)
    {
        animations.push_back(it->first);
    }

    return animations;
}

void SkeletonAnimator::UpdateTime(float timeToAdd)
{
    if(!m_isRunning)
        return;

    GetAnimation(m_currentAnimation).UpdateTime(timeToAdd * m_speedRatio);
}

void SkeletonAnimator::Seek(float time)
{
    GetAnimation(m_currentAnimation).Seek(time);
}

void SkeletonAnimator::Reset()
{
    GetAnimation(m_currentAnimation).Reset();
}

void SkeletonAnimator::Play()
{
    m_isRunning = true;

    if(m_isStopped)
    {
        m_isStopped = false;
        Reset();
    }
}

void SkeletonAnimator::Pause()
{
    m_isRunning = false;
}

void SkeletonAnimator::Stop()
{
    m_isRunning = false;
    m_isStopped = true;
}

void SkeletonAnimator::SetSpeedRatio(float ratio)
{
    if(ratio > 0)
        m_speedRatio = ratio;
}

bool SkeletonAnimator::IsPlaying() const
{
    return m_isRunning;
}

bool SkeletonAnimator::IsPausing() const
{
    return (!m_isRunning) && (!m_isStopped);
}

bool SkeletonAnimator::IsStopped() const
{
    return (!m_isRunning) && m_isStopped;
}

float SkeletonAnimator::GetSpeedRatio() const
{
    return m_speedRatio;
}

void SkeletonAnimator::ApplyToSkeleton(std::vector<Bone*> &boneVec)
{
    GetAnimation(m_currentAnimation).ApplyToSkeleton(boneVec);
}

void SkeletonAnimator::NotifyBoneRenamed(const std::string &oldName, const std::string &newName)
{
    if(oldName == newName)
    {
        return;
    }

    for(std::map<std::string, Animation>::iterator it = m_animations.begin(); it != m_animations.end(); it++)
    {
        it->second.NotifyBoneRenamed(oldName, newName);
    }
}

void SkeletonAnimator::LoadFromXml(TiXmlElement *ele)
{
    m_animations.clear();

    TiXmlNode *child;
    for( child = ele->FirstChild(); child; child = child->NextSibling() )
    {
        if(child->ToElement())
        {
            m_animations[std::string(child->ToElement()->Attribute("name"))] = Animation();
            m_animations[std::string(child->ToElement()->Attribute("name"))].LoadFromXml(child->ToElement());
        }
    }
}

void SkeletonAnimator::SaveToXml(TiXmlElement *ele)
{
    for(std::map<std::string, Animation>::iterator it = m_animations.begin(); it != m_animations.end(); it++)
    {
        TiXmlElement *newEle = new TiXmlElement("Animation");
        newEle->SetAttribute("name", it->first.c_str());
        it->second.SaveToXml(newEle);
        ele->LinkEndChild(newEle);
    }
}

}

}
