class Solution {
public:

    struct RideData {
        vector<int> starts;
        vector<long long> prefixMinDur;
        vector<long long> suffixMinFinish;
    };

    RideData build(vector<pair<int,int>>& rides)
    {
        int n = rides.size();

        RideData data;

        data.starts.resize(n);
        data.prefixMinDur.resize(n);
        data.suffixMinFinish.resize(n);

        for(int i = 0; i < n; i++)
        {
            data.starts[i] = rides[i].first;
        }

        data.prefixMinDur[0] = rides[0].second;

        for(int i = 1; i < n; i++)
        {
            data.prefixMinDur[i] =
                min(data.prefixMinDur[i - 1],
                    (long long)rides[i].second);
        }

        data.suffixMinFinish[n - 1] =
            (long long)rides[n - 1].first +
            rides[n - 1].second;

        for(int i = n - 2; i >= 0; i--)
        {
            data.suffixMinFinish[i] =
                min(data.suffixMinFinish[i + 1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        return data;
    }

    long long query(const RideData& data, long long x)
    {
        int n = data.starts.size();

        long long ans = LLONG_MAX;

        int pos =
            upper_bound(data.starts.begin(),
                        data.starts.end(),
                        x)
            - data.starts.begin();

        // start <= x
        if(pos > 0)
        {
            ans = min(ans,
                      x + data.prefixMinDur[pos - 1]);
        }

        // start > x
        if(pos < n)
        {
            ans = min(ans,
                      data.suffixMinFinish[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> land(n);
        vector<pair<int,int>> water(m);

        for(int i = 0; i < n; i++)
        {
            land[i] =
                {landStartTime[i], landDuration[i]};
        }

        for(int i = 0; i < m; i++)
        {
            water[i] =
                {waterStartTime[i], waterDuration[i]};
        }

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        RideData landData = build(land);
        RideData waterData = build(water);

        long long answer = LLONG_MAX;

        // Land -> Water
        for(int i = 0; i < n; i++)
        {
            long long landFinish =
                (long long)landStartTime[i]
                + landDuration[i];

            answer =
                min(answer,
                    query(waterData, landFinish));
        }

        // Water -> Land
        for(int j = 0; j < m; j++)
        {
            long long waterFinish =
                (long long)waterStartTime[j]
                + waterDuration[j];

            answer =
                min(answer,
                    query(landData, waterFinish));
        }

        return (int)answer;
    }
};