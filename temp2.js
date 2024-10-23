function minimumPages(arr, k) {
    let numBooks = arr.length;
    if (k > numBooks) 
        return -1;
    

function canAllocateBooks(arr, numBooks, k, maxAllowedPages) {
        let allocatedStudents = 1,pagesAllocated = 0;

        for (let i = 0; i < numBooks; i++) {
            if (pagesAllocated + arr[i] > maxAllowedPages) {
                allocatedStudents++;
                pagesAllocated = arr[i];
                if (allocatedStudents > k) {
                    return false;
                }
            } else {
                pagesAllocated += arr[i];
            }
        }
        return true;
    }

    // Binary search for the minimum possible value of the maximum pages
    let low = Math.max(...arr),high = arr.reduce((total, pages) => total + pages, 0);
    let minPages = high;

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);

        if (canAllocateBooks(arr, numBooks, k, mid)) {
            minPages = mid; // If feasible, try to find a lower maximum
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return minPages;
}
