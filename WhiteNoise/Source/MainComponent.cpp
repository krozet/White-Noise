/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()

		String message;
		message << "Preparing to play audio..." << newLine;
		message << " samplesPerBlockExpected = " << samplesPerBlockExpected << newLine;
		message << " sampleRate = " << sampleRate;
		Logger::getCurrentLogger()->writeToLog(message);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()
		
		for (int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
		{
			//pointer to start sample in buffer
			float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);

			//generates a random number betwenn -1 and 1
			Random random;
			for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
			{
				buffer[sample] = (random.nextFloat() * 2.0f) - 1.0f; 
			}
		}
		///TODO Look up clearactivebufferregion and determine if it's needed or not
			// Right now we are not producing any data, in which case we need to clear the buffer
			// (to prevent the output of random noise)
			//bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

		Logger::getCurrentLogger()->writeToLog("Releasing audio resources");
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
    }


private:
    //==============================================================================

    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }
