// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         sort(skill.begin(), skill.end());

//         int n = skill.size();
//         long long totalChemistry = 0;
//         int targetTeamSkill = skill[0] + skill[n - 1];
//         for (int i = 0; i < n / 2; i++) {
//             int currentTeamSkill = skill[i] + skill[n - i - 1];
//             if (currentTeamSkill != targetTeamSkill) {
//                 return -1;
//             }
//             totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
//         }

//         return totalChemistry;
//     }
// };




class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        vector<int> skillFrequency(1001, 0);

        for (int playerSkill : skill) {
            totalSkill += playerSkill;
            skillFrequency[playerSkill]++;
        }

        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetTeamSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;
        for (int playerSkill : skill) {
            int partnerSkill = targetTeamSkill - playerSkill;

            if (skillFrequency[partnerSkill] == 0) {
                return -1;
            }

            totalChemistry += (long long)playerSkill * (long long)partnerSkill;
            skillFrequency[partnerSkill]--;
        }
        return totalChemistry / 2;
    }
};