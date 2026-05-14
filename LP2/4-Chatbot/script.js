function sendMessage(){

    let userInput = document.getElementById("userInput");

    let message = userInput.value.trim();

    if(message === ""){
        return;
    }

    let chatBox = document.getElementById("chatBox");

    // User Message
    let userMessage = document.createElement("div");

    userMessage.className = "user-message";

    userMessage.innerText = message;

    chatBox.appendChild(userMessage);

    chatBox.scrollTop = chatBox.scrollHeight;

    let lowerMessage = message.toLowerCase();

    // Typing Message
    let typing = document.createElement("div");

    typing.className = "typing";

    typing.innerText = "Bot is typing...";

    chatBox.appendChild(typing);

    setTimeout(() => {

        typing.remove();

        // Bot Message
        let botMessage = document.createElement("div");

        botMessage.className = "bot-message";

        let response = "";

        // Rule-Based Replies
        if(lowerMessage.includes("hello") || lowerMessage.includes("hi")){

            response = "Hello 😊 How can I assist you today?";
        }

        else if(lowerMessage.includes("order")){

            response = "Your order will be delivered within 3-5 working days.";
        }

        else if(lowerMessage.includes("refund")){

            response = "Refunds are processed within 7 working days.";
        }

        else if(lowerMessage.includes("payment")){

            response = "We accept UPI, Debit Card, Credit Card, and Net Banking.";
        }

        else if(lowerMessage.includes("delivery")){

            response = "Delivery usually takes 3-5 business days.";
        }

        else if(lowerMessage.includes("cancel")){

            response = "You can cancel your order before shipment.";
        }

        else if(lowerMessage.includes("contact")){

            response = "You can contact us at support@gmail.com";
        }

        else if(lowerMessage.includes("price")){

            response = "Product prices are available on our website.";
        }

        else if(lowerMessage.includes("bye")){

            response = "Thank you for chatting with us 😊 Have a great day!";
        }

        else{

            response = "I'm sorry, I currently do not have information about that. Please ask questions related to orders, payments, refunds, delivery, or contact support.";
        }

        botMessage.innerText = response;

        chatBox.appendChild(botMessage);

        chatBox.scrollTop = chatBox.scrollHeight;

    }, 1000);

    userInput.value = "";
}


// Enter Key Support
document.getElementById("userInput")
.addEventListener("keypress", function(event){

    if(event.key === "Enter"){

        sendMessage();
    }

});