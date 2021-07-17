class RequestManager{
public:
    RequestManager(){}
    void sendRequest(Cloud &c, string request){
        string encoding  = "LINEAR16";
        string sampleRateHertz = "16000";
        string languageCode = "en-US";
        request = "https://" + request + encoding + sampleRateHertz + languageCode;
        Response response;
        c.sendRequest(request, response);
    }
};


// Re-factored Code
class RequestFormatter{
public:
    virtual ~RequestFormatter() = default;
    virtual string formatRequest(string request) = 0;
};


class GoogleRequestFormatter: public RequestFormatter{
public:
    GoogleRequestFormatter() = default;
    string formatRequest(string request) override;
};



