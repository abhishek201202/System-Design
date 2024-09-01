/*
FR - 
1. File Management: Handle the downloading of various file types.
2. Pause/Resume: Support pausing and resuming of downloads.
3. Concurrency: Manage multiple simultaneous downloads.
4. Progress Tracking: Track and display the progress of each download.
5. Error Handling: Manage errors and retry failed downloads.
6. Notification: Notify users about the completion or failure of downloads.
*/

#include<bits/stdc++.h>
using namespace std;

// Enum to represent the status of the download
enum class DownloadStatus {
    NotStarted,
    InProgress,
    Paused,
    Completed,
    Cancelled,
    Failed
};

// File Class
class File {
public:
    string fileID;
    string name;
    string url;
    int size;
    File(const string& id, const string& nm, const string& u, int sz) : fileID(id), name(nm), url(u), size(sz) {}
};

// Downloader Class
class Downloader {
private:
    int currentBytes;
    int totalBytes;
    DownloadStatus status;
public:
    Downloader(int total) : currentBytes(0), totalBytes(total), status(DownloadStatus::NotStarted) {}
    void download() {
        if (status == DownloadStatus::Paused || status == DownloadStatus::NotStarted) {
            status = DownloadStatus::InProgress;
            while (currentBytes < totalBytes) {
                // Simulate downloading
                currentBytes += 100; // Increment download by 100 bytes
                cout << "Downloading... " << (currentBytes * 100) / totalBytes << "% completed.\n";
            }
            status = DownloadStatus::Completed;
        }
    }
    void pauseDownload() {
        if (status == DownloadStatus::InProgress) {
            status = DownloadStatus::Paused;
            cout << "Download paused at " << (currentBytes * 100) / totalBytes << "%.\n";
        }
    }
    void resumeDownload() {
        if (status == DownloadStatus::Paused) {
            cout << "Resuming download...\n";
            download();
        }
    }
    DownloadStatus getStatus() const {
        return status;
    }
    float getProgress() const {
        return (float(currentBytes) / totalBytes) * 100;
    }
};

// DownloadTask Class
class DownloadTask {
public:
    int taskID;
    File file;
    Downloader downloader;
    DownloadStatus status;
    DownloadTask(int id, const File& f) : taskID(id), file(f), downloader(f.size), status(DownloadStatus::NotStarted) {}
    void start() {
        cout << "Starting download for: " << file.name << endl;
        downloader.download();
        status = downloader.getStatus();
    }
    void pause() {
        cout << "Pausing download for: " << file.name << endl;
        downloader.pauseDownload();
        status = downloader.getStatus();
    }
    void resume() {
        cout << "Resuming download for: " << file.name << endl;
        downloader.resumeDownload();
        status = downloader.getStatus();
    }
    void cancel() {
        cout << "Cancelling download for: " << file.name << endl;
        status = DownloadStatus::Cancelled;
    }
    float getProgress() const {
        return downloader.getProgress();
    }
};

// DownloadManager Class
class DownloadManager {
private:
    unordered_map<int, DownloadTask> downloadTasks;
public:
    void addDownloadTask(const DownloadTask& task) {
        downloadTasks[task.taskID] = task;
    }
    void removeDownloadTask(int taskID) {
        downloadTasks.erase(taskID);
    }
    void pauseAll() {
        for (auto& task : downloadTasks) {
            task.second.pause();
        }
    }
    void resumeAll() {
        for (auto& task : downloadTasks) {
            task.second.resume();
        }
    }
    void showAllProgress() {
        for (const auto& task : downloadTasks) {
            cout << "Task " << task.first << " progress: " << task.second.getProgress() << "%\n";
        }
    }
};

// NotificationService Class
class NotificationService {
public:
    void sendNotification(const string& message) {
        cout << "Notification: " << message << endl;
    }
};

// Main function to simulate the system
int main() {
    // Create some files
    File file1("1", "file1.zip", "http://example.com/file1.zip", 1000);
    File file2("2", "file2.zip", "http://example.com/file2.zip", 2000);

    // Create download tasks
    DownloadTask task1(1, file1);
    DownloadTask task2(2, file2);

    // Create download manager and add tasks
    DownloadManager manager;
    manager.addDownloadTask(task1);
    manager.addDownloadTask(task2);

    // Start downloads
    task1.start();
    task2.start();

    // Show progress
    manager.showAllProgress();

    // Pause and resume tasks
    task1.pause();
    task2.pause();

    manager.showAllProgress();

    task1.resume();
    task2.resume();

    manager.showAllProgress();

    // Notification
    NotificationService notification;
    notification.sendNotification("All downloads completed.");

    return 0;
}
