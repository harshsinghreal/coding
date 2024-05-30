class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][]labourRatio = new double[n][2];
        for(int worker=0; worker<n;worker++){
            labourRatio[worker][0] = (double)wage[worker]/quality[worker];
            labourRatio[worker][1] = quality[worker];
        }
        Arrays.sort(labourRatio,(a,b)->Double.compare(a[0],b[0]));
        PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());
        double cumQuality = 0;
        for(int i=0;i<k;i++){
            pq.offer((int)labourRatio[i][1]);
            cumQuality+=labourRatio[i][1];
        }

        double firstLabourRatio = labourRatio[k-1][0];
        double ans = firstLabourRatio*cumQuality;
 
        for(int manager = k; manager<n;manager++){
            firstLabourRatio = labourRatio[manager][0];
            pq.offer((int)labourRatio[manager][1]);
            cumQuality+=labourRatio[manager][1];

            if(pq.size()>k){
                cumQuality-=pq.poll();
            }

            ans= Math.min(ans,firstLabourRatio*cumQuality);

        }

        return ans;
    }
}