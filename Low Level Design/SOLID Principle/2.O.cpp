class MyCloud{
public:
    void sendRequest(string req, string res);
};


class RequestManager{
private:
    RequestFormatter& m_requestFormatter;
    MyCloud& m_cloud;

public:
    RequestManager(RequestFormatter& requestFormatter, MyCloud& mcl);
    void sendRequest(string req);
};




// Re - factored Code
class CloudInterface{
public:
    virtual ~CloudInterf    ace() default;
    virtual void sendRequest(string req, string& res) = 0;
};

class MyCloud: public CloudInterface{
public:
    MyCloud() = default;
    void sendRequest(string req, string res) override;
};

class GoogleCloud: public CloudInterface{
public:
    GoogleCloud() = default;
    void sendRequest(string req, string res) override; 
};

class RequestManager{
private:
    RequestManager& m_requestFormatter;
    CloudInterface& m_cloud;
public:
    RequestManager(RequestManager& requestFormatter, CloudInterface& mcl);
    void sendRequest(string req);
};












