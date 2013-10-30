/*
 Copyright (C) 2012 by Ivan Safrin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
 
#pragma once

#include "PolycodeEditor.h"
#include "PolyUIElement.h"
#include <Polycode.h>
#include "PolycodeUI.h"
#include "utils/TrackballCamera.h"

using namespace Polycode;

class TransformGizmo : public Entity {
	public:
		TransformGizmo();
		~TransformGizmo();
		
		
};

class EntityEditorMainView : public UIElement {
		public:
			EntityEditorMainView();
			~EntityEditorMainView();
			
			void handleEvent(Event *event);			
			void Resize(Number width, Number height);
			void Update();
			
		protected:		
			
			Entity *sideBar;
			UIRect *headerBg;	
			
			Scene *mainScene;
			SceneRenderTexture *renderTexture;
			UIRect *renderTextureShape;			

			TransformGizmo *transformGizmo;
			TrackballCamera *trackballCamera;
			
};

class PolycodeEntityEditor : public PolycodeEditor {
	public:
		PolycodeEntityEditor();
		virtual ~PolycodeEntityEditor();
		
		bool openFile(OSFileEntry filePath);
		void Resize(int x, int y);
		
	protected:
	
		EntityEditorMainView *mainView;
		UIHSizer *mainSizer;
	
};

class PolycodeEntityEditorFactory : public PolycodeEditorFactory {
	public:
		PolycodeEntityEditorFactory() : PolycodeEditorFactory() { extensions.push_back("entity"); }
		PolycodeEditor *createEditor() { return new PolycodeEntityEditor(); }
};
