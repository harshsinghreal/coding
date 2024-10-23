function requiredRunways(arrivalTimes, departureTimes, numberOfPlanes) {
    let num = 24*100;
    for (let i = 0; i < numberOfPlanes; i++) 
        if (departureTimes[i] < arrivalTimes[i]) 
            departureTimes[i] += num;
        
    

    departureTimes.sort((a, b) => a - b);
    arrivalTimes.sort((a, b) => a - b);
    
    let currentRunways = 0,ans = 0,i = 0, j = 0;  
    
    while (i < numberOfPlanes && j < numberOfPlanes) {
        if (arrivalTimes[i] < departureTimes[j]){
            ans = Math.max(ans, ++currentRunways);
            i++;
        }
        else {
            currentRunways--; j++;
        }
    }

    return ans;
}

// Example usage:
console.log(requiredRunways([0900, 0920, 0950, 1000,1100, 1800], [0930, 1200, 1120, 1130,1900, 2000], 6)); // Output: 3
