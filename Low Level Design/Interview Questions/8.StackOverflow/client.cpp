#include<bits/stdc++.h>
using namespace std;

/*
Functional Requirement - 
1. Add / delete user
2. user can search / add / delete, questions / answers / comments
3. Guest can search questions / answers / comments
4. upvote / downvote / closevote / deletevote on questions / answers / comments
5. questions can have lot of answer
6. Questions and answer both can have comments
7. Questions can have all the edit history
8. Notification when, activity happening for a question on which i have commented.
*/

class User {
	int guestId;
	Search searchObj;
public:
	vector<Question> getQuestions(string searchString);
};


class Member: public User {
	Account account;
	vector<Badge> badges;
public:
	void addQuestion(Question question);
	void addComment(Entity entity, Comment comment);
	void addAnswer(Question question, Answer answer);
	void vote(Entity entity, VoteType voteType);
	void addTag(Question question, Tag tag);
	void flag(Entity entity);
	vector<Badge> getBadges();
};


class Account {
	string name;
	Address address;
	int accountId;
	string userName;
	string password;
	string email;
	AccountStatus accountStatus;
	int reputation;
};


class Moderator: public Member {
public:
	bool closeQuestion(Question question);
	bool restoreQuestion(Question question);
};

class Admin: public Member {
public:
	bool blockMember(Member member);
	bool unblockMemeber(Member member);
};

enum AccountStatus {
	BLOCKED, ACTIVE, CLOSED
};

enum VoteType {
	UPVOTE, DOWNVOTE, CLOSEVOTE, DELETEVOTE
};

class Badge {
	string name;
	string description;
};


class Entity {
	int entityId;
	Memeber creator;
	map<VoteType, int> votes;
	Date createdDate;
	vector<Comment> comments;
public:
	bool flagEntity(Member member);
	bool voteEntity(VoteType voteType);
	bool addComment(Comment comment);
};


class Comment: public Entity {
	string message;
};

class Question: public Entity {
	vector<EditHistory> editHistoryList;
	vector<Answer> answerList;
	vector<Tag> tags;
	string title;
	string description;
	QuestionStatus status;

public:
	bool addQuestion();
	bool addTag(Tag tag);
};



class Answer: public Entity {
	string answer;
	bool isAccepted;
public:
	bool addAnswer(Question question);
};

enum QuestionStatus {
	ACTIVE, WOUNTIED, CLOSED, FLAGGED
};


class Tag {
	string name;
	string description;
};

class EditHistory {
	int editHistoryId;
	Member creator;
	Date createdDate;
	Question prevQuestion;
	Question updatedQuestion;
};


int32_t main(){

}