const data = [
    { id: "1", name: "Pramod" },
    { id: "2", last_name: "kharade" },
    { id: "3", name: "Pramod" },
    { id: "4", last_name: "kharade" },
    { id: "5", name: "Vinod" },
    { id: "6", name: "Vinod" },
    { id: "7", color: "green" },
    { id: "8", name: "Sachin" },
    { id: "9", name: "kangude" },
    { id: "10", color: "red" },
    { id: "11", color: "red" },
    { id: "12", gender: "male" },
    { id: "13", gender: "female" },
    { id: "14", gender: "male" },
];

// Step 1: Count occurrences of key-value pairs
const keyValueCounts = {};

data.forEach(obj => {
    for (const [key, value] of Object.entries(obj)) {
        if (!keyValueCounts[key]) {
            keyValueCounts[key] = {};
        }
        keyValueCounts[key][value] = (keyValueCounts[key][value] || 0) + 1;
    }
});

// Step 2: Collect only duplicate key-value pair objects
const groupedDuplicates = {};

data.forEach(obj => {
    for (const [key, value] of Object.entries(obj)) {
        if (keyValueCounts[key][value] > 1) {
            if (!groupedDuplicates[key]) {
                groupedDuplicates[key] = [];
            }
            if (!groupedDuplicates[key].includes(obj)) {
                groupedDuplicates[key].push(obj);
            }
        }
    }
});

// Output the grouped duplicates
console.log(JSON.stringify(groupedDuplicates, null, 2));
