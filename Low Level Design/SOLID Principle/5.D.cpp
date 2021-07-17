class MyCloud{
public:
    void upload16BitPCAudio(string filepath){}
};


class FileUploader{
public:
    FileUploader(MyCloud& mcl);
    void startUpload(string filepath){}
};


// refactored code



class Cloud{
public:
    void upload16BitPCAudio(string filepath) = 0;
};


class MyCloud: public Cloud{
public:
    void upload16BitPCAudio(string filepath){}
};


class FileUploader{
public:
    FileUploader(Cloud& mcl);
    void startUpload(string filepath){}
};


/// solution to above problem

class Cloud{
public:
    void upload(string filepath) = 0;
};

class MyCloud: public Cloud{
public:
    void upload(string filepath){}
};

class FileUploader{
public:
    FileUploader(Cloud& mcl);
    void startUpload(string filepath){}
};
















