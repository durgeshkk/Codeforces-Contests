@echo off
cd E:\Codeforces-Contests

@REM :: Assuming you've already initialized a Git repository
@REM git clone https://github.com/durgeshkk/Codeforces-Contests.git
@REM echo Cloned

git checkout -b feature
echo Feature created
git add .
echo Files Added
git commit -m "Codechef Last Contest Solutions Added"
git push origin feature
echo Push Done, PR Raised
git branch -d feature
echo Feature Branch Deleted