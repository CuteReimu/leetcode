function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let i = 0, j = 0;
    const l = nums1.length + nums2.length;
    if (l == 1) {
        if (nums1.length > 0) {
            return nums1[0];
        }
        return nums2[0];
    }
    let cur = 0, last = 0;
    while (true) {
        if (i < nums1.length) {
            last = cur;
            if (j < nums2.length) {
                if (nums1[i] <= nums2[j]) {
                    cur = nums1[i];
                    i++;
                } else {
                    cur = nums2[j];
                    j++;
                }
            } else {
                cur = nums1[i];
                i++;
            }
        } else if (j < nums2.length) {
            last = cur;
            cur = nums2[j];
            j++;
        } else {
            break;
        }
        if (l%2 == 1) {
            if (i+j > (l-1)/2) return cur;
        } else {
            if (i+j > l/2) return (cur+last) / 2;
        }
    }
    return 0;
};