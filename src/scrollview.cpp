/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <dali-toolkit/dali-toolkit.h>
#include "def_images.h"

using namespace Dali;
using namespace Dali::Toolkit;

class ScrollViewSample : public ConnectionTracker
{
public:
  ScrollViewSample( Application& application )
  : mApplication( application )
  {
    // Connect to the Application's Init signal
    mApplication.InitSignal().Connect( this, &ScrollViewSample::OnInit );
  }

  ~ScrollViewSample()
  {
    // Nothing to do here
  }

  void OnInit( Application& application )
  {
    // Create a ScrollView instance
    ScrollView scrollView = ScrollView::New();
    scrollView.SetParentOrigin( ParentOrigin::CENTER );
    Stage stage = Stage::GetCurrent();
    stage.Add(scrollView);

    // Set the size of scrollView; it covers the entire stage
    Size size = stage.GetSize();
    scrollView.SetSize(size);

    // Add actors to the ScrollView
    for( int i = 0; i < NUM_IMAGES; ++i )
    {
      AddImage( scrollView, size, i );
    }

    // The ScrollView contents are now draggable
    // To enforce horizontal-only scrolling, the Y axis ruler can be disabled
    RulerPtr rulerY = new DefaultRuler();
    rulerY->Disable();
    scrollView.SetRulerY( rulerY );

    // A domain can be applied to rulers to prevent scrolling beyond this boundary
    // In this case, to 4 times the width of the stage, allowing for 4 pages to be scrolled
    RulerPtr rulerX2 = new FixedRuler( size.width );
    rulerX2->SetDomain( RulerDomain( 0.0f, size.width*NUM_IMAGES ) );
    scrollView.SetRulerX( rulerX2 );

    // Connect key event signal
    stage.KeyEventSignal().Connect( this, &ScrollViewSample::OnKeyEvent );
  }

  void AddImage( ScrollView& scrollView, Size& stageSize, int index )
  {
    ImageView imageView = ImageView::New( IMAGE_PATHS[index] );
    imageView.SetResizePolicy( ResizePolicy::FILL_TO_PARENT, Dimension::ALL_DIMENSIONS );
    imageView.SetSizeScalePolicy( SizeScalePolicy::FIT_WITH_ASPECT_RATIO );

    imageView.SetParentOrigin( ParentOrigin::CENTER );
    imageView.SetAnchorPoint( AnchorPoint::CENTER );

    imageView.SetPosition( index * stageSize.x, 0 );
    scrollView.Add( imageView );
  }

  // Main key event handler
  void OnKeyEvent( const KeyEvent& event )
  {
    if( event.state == KeyEvent::Down )
    {
      if( IsKey( event, DALI_KEY_ESCAPE) || IsKey( event, DALI_KEY_BACK ) )
      {
        mApplication.Quit();
      }
    }
  }

  private:
    Application  mApplication;
};

// Entry point for DALi applications
int main( int argc, char **argv )
{
  Application app = Application::New( &argc, &argv );
  ScrollViewSample test( app );
  app.MainLoop();

  return 0;
}
