// Simple virtual assistant implementation in JavaScript

// Function to process user input and generate response
function processInput(input) {
    // Convert input to lowercase for case-insensitive matching
    input = input.toLowerCase();

    // Check for various commands and generate responses
    if (input.includes("hello") || input.includes("hi")) {
        return "Hello! How can I assist you?";
    } else if (input.includes("how are you")) {
        return "I'm just a computer program, so I don't have feelings, but thanks for asking!";
    } else if (input.includes("time")) {
        let date = new Date();
        return "The current time is " + date.toLocaleTimeString();
    } else if (input.includes("date")) {
        let date = new Date();
        return "Today's date is " + date.toLocaleDateString();
    } else if (input.includes("bye")) {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm sorry, I didn't understand that command.";
    }
}

// Function to interact with the user
function startAssistant() {
    // Greet the user
    console.log("Welcome! How can I assist you today?");
    
    // Listen for user input
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.on('line', (input) => {
        // Process user input and get response
        let response = processInput(input);

        // Display response
        console.log(response);

        // Prompt for next input
        console.log("What else can I help you with?");
    });
}

// Start the virtual assistant
startAssistant();
