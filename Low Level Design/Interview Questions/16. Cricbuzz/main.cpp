/*
FR - 
1. support multiple matches 
2. score card for each match
3. update score card after each ball
4. After innings teams get switched (i.e batting and balling teams)


ScoreCard
------------------
Team - 1
Batsman
B1 - (run, balls, 6s, 4s, strikeRate)
Ballers
Ba1 - (overs, median, runsGiven, wicket, noBall, whiteBall, economyRate)
*/

#include<bits/stdc++.h>
using namespace std;

/*
Match
--------------------------------
Team teamA, teamB;
MatchType type;
Inning inning;
startMatch();

MatchType
--------------------------------
numberOfOvers
maxOverBallerAllowed

T20 (MatchType)
--------------------------------
....

OneDay (MatchType)
--------------------------------
....

Inning
--------------------------------
Team battingTeam, balligTeam
vector<Over> overs;
startInning()

Over
--------------------------------
overNumber
vector<Ball> balls

Ball
--------------------------------
ballNumber
BallType ballType (NORMAL, WIDE, NO BALL)
RunType runType (ONE, TWO, THREE, FOUR, FIVE, SIX)
Player playedBy
Player bowledBy
vector<ScoreUpdateObserver> observerList
startBallDelivery()
notify() // this will call ScoreUpdateObserver


BattingScoreUpdateObserver (ScoreUpdateObserver)
--------------------------------
updateScoreCard(Ball ball)

BallingScoreUpdateObserver (ScoreUpdateObserver)
--------------------------------
updateScoreCard(Ball ball)

Team
--------------------------------
string teamName
vector<Player> players;
BattingController battingController;
BowlingController bowlingController;

Player
--------------------------------
name
type(Batsman, Bowler, Fielder)
ScoreCard battingScoreCard, bowlingScoreCard

BattingScoreCard (ScoreCard)
--------------------------------
totalRun, balls, 6s, 4s, strikeRate

BowlingScoreCard (ScoreCard)
--------------------------------
overs, median, runsGiven, wicket, noBall, whiteBall, economyRate

BattingController
--------------------------------
Player strikePlayer
Player nonStrikePlayer
getNextBatsman()

BowlingController
--------------------------------
Player currentPalyer
getNextBowler()


*/
