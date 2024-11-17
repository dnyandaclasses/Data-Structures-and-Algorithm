**Problem Statement:**
Given an array of objects where each object contains key-value pairs, the goal is to identify duplicate key-value pairs across all objects. A key-value pair is considered a duplicate if it appears in more than one object.
The output should group all objects containing these duplicate key-value pairs under their respective keys. Each key in the output will have an array of objects that share at least one duplicate key-value pair. Objects without any duplicate key-value pairs should not be included in the output.
**Input:**

[
    { "id": "1", "name": "Deepika" },
    { "id": "2", "last_name": "Walanjkar" },
    { "id": "3", "name": "Deepika" },
    { "id": "4", "last_name": "Walanjkar" },
    { "id": "5", "name": "Vinod" },
    { "id": "6", "name": "Vinod" },
    { "id": "7", "color": "green" },
    { "id": "8", "name": "Sachin" },
    { "id": "9", "name": "kangude" },
    { "id": "10", "color": "red" },
    { "id": "11", "color": "red" }
]

**Output:**

{
  "name": [
    { "id": "1", "name": "Deepika" },
    { "id": "3", "name": "Deepika" },
    { "id": "5", "name": "Vinod" },
    { "id": "6", "name": "Vinod" }
  ],
  "last_name": [
    { "id": "2", "last_name": "Walanjkar" },
    { "id": "4", "last_name": "Walanjkar" }
  ],
  "color": [
    { "id": "10", "color": "red" },
    { "id": "11", "color": "red" }
  ]
}




**Constraints:**
Each object in the input array can have multiple key-value pairs.
Key-value pairs that are unique across all objects should not appear in the output.
Objects may contain different sets of keys.

This problem requires implementing an algorithm to:
Count the occurrences of all key-value pairs in the input.
Filter the objects containing duplicate key-value pairs.
Group the filtered objects by their duplicate keys in the final output.
