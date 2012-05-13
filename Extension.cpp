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
                                  _("Extension permettant de g�rer les animations sous forme d'une squelette."),
                                  "Victor Levasseur",
                                  "Freeware")


            //Declaration of all objects available
            DECLARE_OBJECT("Skeleton",
                           _("Squelette"),
                           _("Squelette d�formable selon des animations."),
                           "res/Skeleton24.png",
                           &CreateSkeletonObject,
                           &DestroySkeletonObject,
                           "SkeletonObject");

                #if defined(GD_IDE_ONLY)

                objInfos.SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_OBJECT_ACTION("Volume",
                               _("Volume"),
                               _("Modifie le volume d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ au volume de _PARAM0_"),
                               _("Param�tres"),
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
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur"), "", false);
                    instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("SetPitch").SetManipulatedType("number").SetAssociatedGetter("GetPitch").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("Attenuation",
                               _("Att�nuation"),
                               _("Modifie l'att�nuation d'un objet son."),
                               _("Faire _PARAM2__PARAM1_ � l'att�nuation de _PARAM0_"),
                               _("Param�tres"),
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
                               _("Active ou d�sactive le bouclage d'un son."),
                               _("Jouer _PARAM0_ en boucle : _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("yesorno", _("Jouer en boucle"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("SetLoop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_ACTION()


                DECLARE_OBJECT_ACTION("RelativeToListener",
                               _("Relativit� � l'�couteur"),
                               _("Active ou d�sactive la relativit� d'un son � l'�couteur."),
                               _("Faire _PARAM0_ relatif � l'�couteur : _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("yesorno", _("Relatif � l'�couteur"), "", false);

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
                               _("Arr�ter"),
                               _("Arr�ter de jouer un son."),
                               _("Arr�ter de jouer le son _PARAM0_"),
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
                               _("Le volume de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetVolume").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Pitch",
                               _("Pitch"),
                               _("Teste le pitch d'un son."),
                               _("Le pitch de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetPitch").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Attenuation",
                               _("Att�nuation"),
                               _("Teste l'att�nuation d'un son."),
                               _("L'att�nuation de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetAttenuation").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("MinDistance",
                               _("Distance minimale"),
                               _("Teste la distance minimale d'un son."),
                               _("La distance minimale de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


                    instrInfo.cppCallingInformation.SetFunctionName("GetMinDistance").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("ZPos",
                               _("Position Z"),
                               _("Teste la position Z d'un son."),
                               _("La position Z de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);
                    instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                    instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetZPos").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Loop",
                               _("Bouclage"),
                               _("Teste si un son est jou� en boucle."),
                               _("_PARAM0_ est jou� en boucle"),
                               _("Param�tres"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetLoop").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("Playing",
                               _("En train d'�tre jou�"),
                               _("Teste si un son est en train d'�tre jou�."),
                               _("_PARAM0_ est en train d'�tre jou�"),
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
                               _("Arr�t�"),
                               _("Teste si un son est arr�t�."),
                               _("_PARAM0_ est arr�t�"),
                               _("Lecture"),
                               "res/actions/son24.png",
                               "res/actions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsStopped").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_CONDITION("RelativeToListener",
                               _("Relativit� � l'�couteur"),
                               _("Teste si un son est relatif � l'�couteur."),
                               _("_PARAM0_ est relatif � l'�couteur"),
                               _("Param�tres"),
                               "res/conditions/son24.png",
                               "res/conditions/son.png");

                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("IsRelativeToListener").SetIncludeFile("SkeletonObject/SkeletonObject.h");

                DECLARE_END_OBJECT_CONDITION()


                DECLARE_OBJECT_EXPRESSION("Volume", _("Volume"), _("Volume"), _("Param�tres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetVolume").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("Pitch", _("Pitch"), _("Pitch"), _("Param�tres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetPitch").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("Attenuation", _("Att�nuation"), _("Att�nuation"), _("Param�tres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetAttenuation").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("MinDistance", _("Distance minimale"), _("Distance minimale"), _("Param�tres"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetMinDistance").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()


                DECLARE_OBJECT_EXPRESSION("ZPos", _("Position Z"), _("Position Z"), _("Position"), "res/actions/son.png")
                    instrInfo.AddParameter("object", _("Objet"), "Skeleton", false);

                    instrInfo.cppCallingInformation.SetFunctionName("GetZPos").SetIncludeFile("SkeletonObject/SkeletonObject.h");
                DECLARE_END_OBJECT_EXPRESSION()

            #endif
            DECLARE_END_OBJECT()

            // Actions li�es � l'�couteur
            #if defined(GD_IDE_ONLY)
            DECLARE_ACTION("ListenerX",
                           _("Position x"),
                           _("Modifier la position x de l'�couteur."),
                           _("Faire _PARAM0__PARAM1_ � la position x de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerX").SetManipulatedType("number").SetAssociatedGetter("GetListenerX").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerY",
                           _("Position y"),
                           _("Modifier la position y de l'�couteur."),
                           _("Faire _PARAM0__PARAM1_ � la position y de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerY").SetManipulatedType("number").SetAssociatedGetter("GetListenerY").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerZ",
                           _("Position z"),
                           _("Modifier la position z de l'�couteur."),
                           _("Faire _PARAM0__PARAM1_ � la position z de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerZ").SetManipulatedType("number").SetAssociatedGetter("GetListenerZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionX",
                           _("Direction en x"),
                           _("Modifier la direction vers laquelle est tourn� l'�couteur en x."),
                           _("Faire _PARAM0__PARAM1_ � la direction en x de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionX").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionX").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionY",
                           _("Direction en y"),
                           _("Modifier la direction vers laquelle est tourn� l'�couteur en y."),
                           _("Faire _PARAM0__PARAM1_ � la direction en y de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionY").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionY").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            DECLARE_ACTION("ListenerDirectionZ",
                           _("Direction en z"),
                           _("Modifier la direction vers laquelle est tourn� l'�couteur en z."),
                           _("Faire _PARAM0__PARAM1_ � la direction en z de l'�couteur"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur"), "", false);
                instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetListenerDirectionZ").SetManipulatedType("number").SetAssociatedGetter("GetListenerDirectionZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_ACTION()


            // Conditions li�es � l'�couteur
            DECLARE_CONDITION("ListenerX",
                           _("Position x"),
                           _("Tester la position x de l'�couteur."),
                           _("La position x de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerX").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerY",
                           _("Position y"),
                           _("Tester la position y de l'�couteur."),
                           _("La position y de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerY").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerZ",
                           _("Position z"),
                           _("Tester la position z de l'�couteur."),
                           _("La position z de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerZ").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionX",
                           _("Direction x"),
                           _("Tester la direction vers laquelle est tourn� l'�couteur en x."),
                           _("La direction en x de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionX").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionY",
                           _("Direction y"),
                           _("Tester la direction vers laquelle est tourn� l'�couteur en y."),
                           _("La direction en y de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionY").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_CONDITION("ListenerDirectionZ",
                           _("Direction z"),
                           _("Tester la direction vers laquelle est tourn� l'�couteur en z."),
                           _("La direction en z de l'�couteur est _PARAM1_ � _PARAM0_"),
                           _("Ecouteur"),
                           "res/actions/son24.png",
                           "res/actions/son.png");

                instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionZ").SetManipulatedType("number").SetIncludeFile("SkeletonObject/SkeletonListener.h");

            DECLARE_END_CONDITION()


            DECLARE_EXPRESSION("ListenerX", _("Position x"), _("Position x de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerX").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerY", _("Position y"), _("Position y de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerY").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerZ", _("Position z"), _("Position z de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionX", _("Direction en x"), _("Direction en x de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionX").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionY", _("Direction en y"), _("Direction en y de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionY").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()

            DECLARE_EXPRESSION("ListenerDirectionZ", _("Direction en z"), _("Direction en z de l'�couteur"), _("Ecouteur"), "res/actions/son.png")
                instrInfo.cppCallingInformation.SetFunctionName("GetListenerDirectionZ").SetIncludeFile("SkeletonObject/SkeletonListener.h");
            DECLARE_END_EXPRESSION()
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
