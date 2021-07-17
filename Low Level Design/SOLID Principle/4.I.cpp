class AudioDeviceManager{
public:
    virtual ~AudioDeviceManager() = default;
    virtual bool start(AudioDevice &d) = 0;
    virtual bool stop(AudioDevice &d) = 0;
    virtual int readData(char** buffer, int size) = 0;
    virtual int writeData(char** buffer, int size) = 0;
};


class MyAudioInputDeviceManager: public AudioDeviceManager{
public:
    bool start(AudioDevice &d) override;
    bool stop(AudioDevice &d) override;
    int readData(char** buffer, int size) override;
    int writeData(char** buffer, int size) override;
};



// refactored code

class AudioDeviceManager{
public:
    virtual ~AudioDeviceManager() = default;
    virtual bool start(AudioDevice &d) = 0;
    virtual bool stop(AudioDevice &d) = 0;
};

class AudioInputDeviceManager{
public:
    virtual ~AudioDeviceManager() = default;
    virtual int readData(char** buffer, int size) = 0;
};

class AudioOutputDeviceManager{
public:
    virtual ~AudioDeviceManager() = default;
    virtual int writeData(char** buffer, int size) = 0;
};

class MyAudioInputDeviceManager: public AudioDeviceManager, public AudioInputDeviceManager{
public:
    bool start(AudioDevice &d) override;
    bool stop(AudioDevice &d) override;
    int readData(char** buffer, int size) override;
};







