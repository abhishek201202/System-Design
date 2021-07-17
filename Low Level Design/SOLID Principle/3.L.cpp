class RecoginitionResult{
public:
    virtual ~RecoginitionResult() = default;
    virtual double getConfidenceScore() = 0;
};


class MyCloudRecognitionResult: public RecoginitionResult{
public:
    // returns confidence score value [10.0 - 100.0]
    double getConfidenceScore() override;
};


class GoogleCloudRecognitionResult: public RecoginitionResult{
public:
    // retunrs confidence score value [0.0 - 10.0]
    double getConfidenceScore() override;
};


/*********************************************************
example - 2
********************************************************/

class RecoginitionResult{
public:
    virtual ~RecoginitionResult() = default;
    virtual double setSampleRate(int hrtz) = 0;
};


class MyCloudRecognitionResult: public RecoginitionResult{
public:
    // sets Audio sample rates [8000kHz - 16000kHz]
    double setSampleRate(int hrtz) override;
};


class GoogleCloudRecognitionResult: public RecoginitionResult{
public:
    // sets Audio sample rates [8000kHz - 48000kHz]
    double setSampleRate(int hrtz) override;
};



