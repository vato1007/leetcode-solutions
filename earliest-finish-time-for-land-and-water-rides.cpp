class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int earliestLandEnd = INT_MAX;
        int earliestWaterEnd = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            earliestLandEnd = min(
                earliestLandEnd,
                landStartTime[i] + landDuration[i]
            );
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            earliestWaterEnd = min(
                earliestWaterEnd,
                waterStartTime[j] + waterDuration[j]
            );
        }

        int answer = INT_MAX;

        // Land ride first, then water ride
        for (int j = 0; j < waterStartTime.size(); j++) {
            int finishTime = max(earliestLandEnd, waterStartTime[j])
                             + waterDuration[j];
            answer = min(answer, finishTime);
        }

        // Water ride first, then land ride
        for (int i = 0; i < landStartTime.size(); i++) {
            int finishTime = max(earliestWaterEnd, landStartTime[i])
                             + landDuration[i];
            answer = min(answer, finishTime);
        }

        return answer;
    }
};
