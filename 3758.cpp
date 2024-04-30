#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Entry {
  int i;
  int j;
  int s;
};

struct FinalScore {
  int team_id;
  int total_score;
  int total_submission;
  int last_submission;
};

int testcase;
int n, k, t, m;
vector<Entry> entries;
int max_scores[101][101];
int total_score[101];
int submission_count[101];
int last_submission[101];

void GetInput1() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> testcase;
}

void GetInput2() {
  cin >> n >> k >> t >> m;

  for (int i = 0; i < m; i++) {
    Entry entry;
    cin >> entry.i >> entry.j >> entry.s;
    entries.push_back(entry);
  }
}

bool CompareFinalScore(FinalScore final_score1, FinalScore final_score2) {
  if (final_score1.total_score > final_score2.total_score)
    return true;
  else if (final_score1.total_score == final_score2.total_score) {
    if (final_score1.total_submission < final_score2.total_submission)
      return true;
    else if (final_score1.total_submission == final_score2.total_submission)
      return final_score1.last_submission < final_score2.last_submission;
    else
      return false;
  }
  else
    return false;
}

void Solve() {
  // Calculate the maximum score for each team and problem.
  // Calculate the submission count for each team.
  // Calculate the last submission for each team.
  for (unsigned int i = 0; i < entries.size(); i++) {
    Entry& entry = entries[i];
    max_scores[entry.i][entry.j] = max(max_scores[entry.i][entry.j], entry.s);
    submission_count[entry.i]++;
    last_submission[entry.i] = i;
  }

  // Calculate the total score for each team.
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      total_score[i] += max_scores[i][j];
    }
  }

  // Add final scores for each team.
  vector<FinalScore> final_scores;
  for (int i = 1; i <= n; i++) {
    FinalScore final_score = { i, total_score[i], submission_count[i], last_submission[i] };
    final_scores.push_back(final_score);
  }

  // Sort the final scores based on the criteria.
  sort(final_scores.begin(), final_scores.end(), CompareFinalScore);

  // Search for the team_id t and print its rank.
  for (unsigned int i = 0; i < final_scores.size(); i++) {
    FinalScore& final_score = final_scores[i];
    //cout << i + 1 << "등: " << final_score.team_id << ", " << final_score.total_score << ", " << final_score.total_submission << ", " << final_score.last_submission << endl;
    if (final_score.team_id == t)
      cout << i + 1 << '\n';
  }
}

int main(void) {
  GetInput1();
  for (int i = 0; i < testcase; i++) {
    memset(max_scores, 0, sizeof(max_scores));
    memset(total_score, 0, sizeof(total_score));
    memset(submission_count, 0, sizeof(submission_count));
    entries.clear();
    GetInput2();
    Solve();
  }
}