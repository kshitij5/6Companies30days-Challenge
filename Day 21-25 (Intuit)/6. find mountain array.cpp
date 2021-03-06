int findInMountainArray(int target, MountainArray& mountainArr) {
    bool flag = false;
    int n = mountainArr.length();
    int low = 0, high = n - 1;
    int k;
    int peak;
    while (low <= high)
    {
        int k = (low + high) / 2;
        if ((k == 0 || mountainArr.get(k) >= mountainArr.get(k - 1)) && ((k == n - 1 || mountainArr.get(k) >= mountainArr.get(k + 1))))
        {
            peak = k;
            flag = true;
            break;
        }
        if (k > 0 && (mountainArr.get(k) <= mountainArr.get(k - 1)))
        {
            high = k - 1;
        }
        else
        {
            low = k + 1;
        }
    }
    if (!flag)
    {
        peak = k - 1;
    }
    bool first = false;
    low = 0;
    high = peak;
    int ans;
    while (low <= high)
    {

        int k = (low + high) / 2;
        int curr = mountainArr.get(k);
        if (curr == target)
        {
            ans = k;
            first = true;
            return ans;

            break;
        }
        if (curr > target)
        {
            high = k - 1;
        }
        else
        {
            low = k + 1;
        }
    }
    if (!first)
    {
        low = peak + 1;
        high = n - 1;
        while (low <= high)
        {
            int k = (low + high) / 2;
            int curr = mountainArr.get(k);
            if (curr == target)
            {
                ans = k;
                first = true;
                return ans;

                break;
            }
            if (curr > target)
            {
                low = k + 1;
            }
            else
            {
                high = k - 1;
            }
        }

    }
    if (!first)
    {
        return -1;
    }

    return ans;

}
};