// Pseudocode:
// left=1, right=n;

// i = (left + right) / 2;

// while (left != i) and (i != right) do

//     if a[i]>=k then right = i;

//     else left = i;

//     i = (left + right) / 2;

// for i = left to right do

// if a[i]>=k then return a[i];

// cout << "Not found";

// Nhập một số thực nằm trong khoảng từ 0 đến 1 (0 <= key <= 1). Tìm x để sin x = key.

left=0, right=PI/2;

i = (left + right) / 2;

while (left != i) and (i != right) do

    if sin(i)>=key then right = i;

    else left = i;

    i = (left + right) / 2;
cout << (l+r)/2;