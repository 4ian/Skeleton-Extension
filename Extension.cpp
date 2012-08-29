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

#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "SkeletonObject.h"
#include <boost/version.hpp>

/**
 * This class declare information about the extension.
 */
class Extension : public ExtensionBase
{
    public:

        /**
         * Constructor of an extension declares everything the extension contains : Objects, actions, conditions and expressions.
         */
        Extension()
        {
            DECLARE_THE_EXTENSION("SkeletonObject",
                                  _("Objet Squelette"),
                                  _(L"Extension permettant de gérer les animations sous forme d'une squelette."),
                                  "Victor Levasseur",
                                  "zlib")


            //Declaration of all objects available
            DECLARE_OBJECT("Skeleton",
                           _("Squelette"),
                           _(L"Squelette déformable selon des animations."),
                           "res/Skeleton32.png",
                           &CreateSkeletonObject,
                           &DestroySkeletonObject,
                           "SkeletonObject");

                #if defined(GD_IDE_ONLY)

                objInfos.SetIncludeFile("SkeletonObject/SkeletonObject.h");

                /**
                Actions/Conditions for reading
                */

                DECLARE_OBJECT_ACTION("Play",
                               _("Jouer l'animation"),
                               _("Joue l'animation en cours."),
                               _("Jouer l'animation de _PARAM0_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Play").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()

                DECLARE_OBJECT_CONDITION("IsPlaying",
                               _("L'animation se joue"),
                               _("Teste si l'animation se joue."),
                               _("L'animation de _PARAM0_ se joue"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsPlaying").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()

                DECLARE_OBJECT_ACTION("Pause",
                               _("Mettre en pause l'animation"),
                               _("Met en pause l'animation en cours."),
                               _("Mettre en pause l'animation de _PARAM0_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Pause").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()

                DECLARE_OBJECT_CONDITION("IsPausing",
                               _("L'animation est en pause"),
                               _("Teste si l'animation est en pause."),
                               _("L'animation de _PARAM0_ est en pause"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsPausing").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()

                DECLARE_OBJECT_ACTION("Stop",
                               _("Arrêter l'animation"),
                               _("Arrête l'animation en cours."),
                               _("Arrêter l'animation de _PARAM0_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Stop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()

                DECLARE_OBJECT_CONDITION("IsStopped",
                               _(L"L'animation est arrêtée"),
                               _(L"Teste si l'animation est arrêtée."),
                               _(L"L'animation de _PARAM0_ est arrêtée"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsStopped").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()

                DECLARE_OBJECT_ACTION("SetSpeedRatio",
                               _("Changer la vitesse de l'animation"),
                               _(L"Change la vitesse de l'animation.\n1 = Vitesse normale, 1< = Ralentit, >1 = Accéléré"),
                               _(L"Mettre la vitesse de l'animation de _PARAM0_ à _PARAM2__PARAM1_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("SetSpeedRatio").SetManipulatedType("number").SetAssociatedGetter("GetSpeedRatio").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()

                DECLARE_OBJECT_CONDITION("TestSpeedRatio",
                               _("Tester la vitesse de l'animation"),
                               _("Teste la vitesse de l'animation."),
                               _("La vitesse de l'animation de _PARAM0_ est _PARAM2__PARAM1_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe de comparaison"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetSpeedRatio").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()

                DECLARE_OBJECT_EXPRESSION("GetSpeedRatio", _("Vitesse de l'animation"), _("Vitesse de l'animation"), _("Lecture"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetSpeedRatio").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()

                /**
                Actions/Conditions for changing animations
                */

                DECLARE_OBJECT_ACTION("SetAnimation",
                               _("Changer d'animation"),
                               _("Change l'animation en cours."),
                               _(L"Mettre l'animation _PARAM1_ à _PARAM0_"),
                               _("Animation"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("string", _("Nom"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("SetAnimation").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()

                DECLARE_OBJECT_CONDITION("TestAnimation",
                               _("Tester le nom de l'animation qui se joue"),
                               _("Teste le nom de l'animation qui se joue."),
                               _("Le nom de l'animation de _PARAM0_ est _PARAM2__PARAM1_"),
                               _("Animation"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("string", _("Nom"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe de comparaison"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetAnimation").SetManipulatedType("string").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()

                DECLARE_OBJECT_STR_EXPRESSION("GetCurrentAnimation", _("Animation actuelle"), _("Animation actuelle"), _("Animation"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetAnimation").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_STR_EXPRESSION()

                /*DECLARE_OBJECT_ACTION("Volume",
                               _("Volume"),
                               _("Modifie le volume d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ au volume de _PARAM0_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("SetVolume").SetManipulatedType("number").SetAssociatedGetter("GetVolume").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Pitch",
                               _("Pitch"),
                               _("Modifie le pitch d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ au pitch de _PARAM0_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("SetPitch").SetManipulatedType("number").SetAssociatedGetter("GetPitch").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Attenuation",
                               _("Atténuation"),
                               _("Modifie l'atténuation d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ à l'atténuation de _PARAM0_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("SetAttenuation").SetManipulatedType("number").SetAssociatedGetter("GetAttenuation").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("ZPos",
                               _("Position Z"),
                               _("Modifie le volume d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ au volume de _PARAM0_"),
                               _("Position"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("SetZPos").SetManipulatedType("number").SetAssociatedGetter("GetZPos").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Loop",
                               _("Bouclage"),
                               _("Active ou désactive le bouclage d'un son."),
                               _("Jouer _PARAM0_ en boucle : _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("yesorno", _("Jouer en boucle"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("SetLoop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("RelativeToListener",
                               _("Relativité à l'écouteur"),
                               _("Active ou désactive la relativité d'un son à l'écouteur."),
                               _("Faire _PARAM0_ relatif à l'écouteur : _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("yesorno", _("Relatif à l'écouteur"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("SetRelativeToListener").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Play",
                               _("Jouer"),
                               _("Jouer un son."),
                               _("Jouer le son _PARAM0_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Play").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Stop",
                               _("Arrêter"),
                               _("Arrêter de jouer un son."),
                               _("Arrêter de jouer le son _PARAM0_"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Stop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Pause",
                               _("Pause"),
                               _("Mettre un son en pause."),
                               _("Mettre le son _PARAM0_ en pause"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("Pause").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_CONDITION("Volume",
                               _("Volume"),
                               _("Teste le volume d'un son."),
                               _("Le volume de _PARAM0_ est _PARAM2_ à _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetVolume").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Pitch",
                               _("Pitch"),
                               _("Teste le pitch d'un son."),
                               _("Le pitch de _PARAM0_ est _PARAM2_ à _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetPitch").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Attenuation",
                               _("Atténuation"),
                               _("Teste l'atténuation d'un son."),
                               _("L'atténuation de _PARAM0_ est _PARAM2_ à _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetAttenuation").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("MinDistance",
                               _("Distance minimale"),
                               _("Teste la distance minimale d'un son."),
                               _("La distance minimale de _PARAM0_ est _PARAM2_ à _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetMinDistance").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("ZPos",
                               _("Position Z"),
                               _("Teste la position Z d'un son."),
                               _("La position Z de _PARAM0_ est _PARAM2_ à _PARAM1_"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetZPos").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Loop",
                               _("Bouclage"),
                               _("Teste si un son est joué en boucle."),
                               _("_PARAM0_ est joué en boucle"),
                               _("Paramètres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetLoop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Playing",
                               _("En train d'être joué"),
                               _("Teste si un son est en train d'être joué."),
                               _("_PARAM0_ est en train d'être joué"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsPlaying").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Paused",
                               _("En pause"),
                               _("Teste si un son est en pause."),
                               _("_PARAM0_ est en pause."),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsPaused").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Stopped",
                               _("Arrêté"),
                               _("Teste si un son est arrêté."),
                               _("_PARAM0_ est arrêté"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsStopped").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("RelativeToListener",
                               _("Relativité à l'écouteur"),
                               _("Teste si un son est relatif à l'écouteur."),
                               _("_PARAM0_ est relatif à l'écouteur"),
                               _("Paramètres"),
                               "res/conditions/son24.png",
                               "res/conditions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsRelativeToListener").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_EXPRESSION("Volume", _("Volume"), _("Volume"), _("Paramètres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetVolume").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("Pitch", _("Pitch"), _("Pitch"), _("Paramètres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetPitch").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("Attenuation", _("Atténuation"), _("Atténuation"), _("Paramètres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetAttenuation").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("MinDistance", _("Distance minimale"), _("Distance minimale"), _("Paramètres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetMinDistance").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("ZPos", _("Position Z"), _("Position Z"), _("Position"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetZPos").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()*/

            #endif
            DECLARE_END_OBJECT()

            // Actions liées à l'écouteur
            #if defined(GD_IDE_ONLY)
            /*DECLARE_ACTION("ListenerX",
                           _("Position x"),
                           _("Modifier la position x de l'écouteur."),
                           _("Faire _PARAM0__PARAM1_ à la position x de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerX").SetManipulatedType("number").SetAssociatedGetter("GetListenerX").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerY",
                           _("Position y"),
                           _("Modifier la position y de l'écouteur."),
                           _("Faire _PARAM0__PARAM1_ à la position y de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerY").SetManipulatedType("number").SetAssociatedGetter("GetListenerY").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerZ",
                           _("Position z"),
                           _("Modifier la position z de l'écouteur."),
                           _("Faire _PARAM0__PARAM1_ à la position z de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerZ").SetManipulatedType("number").SetAssociatedGetter("GetListenerZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionX",
                           _("Direction en x"),
                           _("Modifier la direction vers laquelle est tourné l'écouteur en x."),
                           _("Faire _PARAM0__PARAM1_ à la direction en x de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionX").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionX").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionY",
                           _("Direction en y"),
                           _("Modifier la direction vers laquelle est tourné l'écouteur en y."),
                           _("Faire _PARAM0__PARAM1_ à la direction en y de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionY").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionY").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionZ",
                           _("Direction en z"),
                           _("Modifier la direction vers laquelle est tourné l'écouteur en z."),
                           _("Faire _PARAM0__PARAM1_ à la direction en z de l'écouteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionZ").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            // Conditions liées à l'écouteur
            DECLARE_CONDITION("ListenerX",
                           _("Position x"),
                           _("Tester la position x de l'écouteur."),
                           _("La position x de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerX").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerY",
                           _("Position y"),
                           _("Tester la position y de l'écouteur."),
                           _("La position y de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerY").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerZ",
                           _("Position z"),
                           _("Tester la position z de l'écouteur."),
                           _("La position z de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerZ").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionX",
                           _("Direction x"),
                           _("Tester la direction vers laquelle est tourné l'écouteur en x."),
                           _("La direction en x de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionX").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionY",
                           _("Direction y"),
                           _("Tester la direction vers laquelle est tourné l'écouteur en y."),
                           _("La direction en y de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionY").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionZ",
                           _("Direction z"),
                           _("Tester la direction vers laquelle est tourné l'écouteur en z."),
                           _("La direction en z de l'écouteur est _PARAM1_ à _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur à tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionZ").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_EXPRESSION("ListenerX", _("Position x"), _("Position x de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerX").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerY", _("Position y"), _("Position y de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerY").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerZ", _("Position z"), _("Position z de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionX", _("Direction en x"), _("Direction en x de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionX").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionY", _("Direction en y"), _("Direction en y de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionY").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionZ", _("Direction en z"), _("Direction en z de l'écouteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()*/
            #endif

            CompleteCompilationInformation();
        };
        virtual ~Extension() {};

    protected:
    private:

        /**
         * This function is called by Game Develop so
         * as to complete information about how the extension was compiled ( which libs... )
         * -- Do not need to be modified. --
         */
        void CompleteCompilationInformation()
        {
            #if defined(GD_IDE_ONLY)
            compilationInfo.runtimeOnly = false;
            #else
            compilationInfo.runtimeOnly = true;
            #endif

            #if defined(__GNUC__)
            compilationInfo.gccMajorVersion = __GNUC__;
            compilationInfo.gccMinorVersion = __GNUC_MINOR__;
            compilationInfo.gccPatchLevel = /*__GNUC_PATCHLEVEL__*/1;
            #endif

            compilationInfo.boostVersion = BOOST_VERSION;

            compilationInfo.sfmlMajorVersion = 2;
            compilationInfo.sfmlMinorVersion = 0;

            #if defined(GD_IDE_ONLY)
            compilationInfo.wxWidgetsMajorVersion = wxMAJOR_VERSION;
            compilationInfo.wxWidgetsMinorVersion = wxMINOR_VERSION;
            compilationInfo.wxWidgetsReleaseNumber = wxRELEASE_NUMBER;
            compilationInfo.wxWidgetsSubReleaseNumber = wxSUBRELEASE_NUMBER;
            #endif

            compilationInfo.gdlVersion = RC_FILEVERSION_STRING;
            compilationInfo.sizeOfpInt = sizeof(int*);

            compilationInfo.informationCompleted = true;
        }
};

/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new Extension;
}

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void GD_EXTENSION_API DestroyGDExtension(ExtensionBase * p) {
    delete p;
}
