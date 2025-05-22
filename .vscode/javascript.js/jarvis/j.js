function processInput(input) {
    input = input.toLowerCase();

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

function sendUserMessage() {
    var userInput = document.getElementById("user-input").value;
    if (userInput.trim() === "") return;

    displayMessage("user", userInput);

    var response = processInput(userInput);
    displayMessage("assistant", response);

    document.getElementById("user-input").value = "";
}

function displayMessage(sender, message) {
    var chatContainer = document.getElementById("chat-container");
    var messageElement = document.createElement("div");
    messageElement.classList.add("chat-message");
    messageElement.classList.add(sender === "user" ? "user-message" : "assistant-message");
    messageElement.innerText = message;
    chatContainer.appendChild(messageElement);
}

