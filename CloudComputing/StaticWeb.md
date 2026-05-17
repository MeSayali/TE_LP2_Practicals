## Commands
```bash
chmod 400 temp.pem
```

```
ssh -i fileShare.pem ubuntu@13.127.144.31
```

```
 nano index.html

 nano script.js

```

index:
```
<!DOCTYPE html>
<html>
<head>
    <title>Ayurvedic Chatbot</title>
</head>

<body style="margin:0;font-family:Arial;background:#f0f0f0;">

    <!-- Navbar -->

    <div style="background:green;color:white;padding:15px;text-align:center;">
        <h1>Ayurvedic Health Care</h1>
    </div>

    <!-- Hero -->

    <div style="text-align:center;padding:30px;background:#dff5df;">
        <h2 style="color:green;">Natural Healing with Ayurveda</h2>

        <p>Ask chatbot for Ayurvedic remedies.</p>
    </div>

    <!-- Cards -->

    <div style="display:flex;justify-content:center;gap:20px;padding:20px;">

        <div style="background:white;padding:20px;width:200px;border-radius:10px;">
            <h3>Cold</h3>
            <p>Drink Tulsi tea.</p>
        </div>

        <div style="background:white;padding:20px;width:200px;border-radius:10px;">
            <h3>Fever</h3>
            <p>Drink herbal kadha.</p>
        </div>

        <div style="background:white;padding:20px;width:200px;border-radius:10px;">
            <h3>Headache</h3>
            <p>Take proper rest.</p>
        </div>

    </div>

    <!-- Chatbot -->

    <div style="width:500px;margin:auto;background:white;padding:20px;border-radius:10px;">

        <h2 style="text-align:center;color:green;">
            Ayurvedic Chatbot
        </h2>

        <div id="chatbox"
             style="height:300px;border:1px solid gray;padding:10px;overflow:auto;">

            <div style="background:#ffd6d6;padding:10px;border-radius:5px;margin:5px;">
                Namaste! Ask me about cold, cough, fever or headache.
            </div>

        </div>

        <div style="display:flex;margin-top:10px;">

            <input
                type="text"
                id="userInput"
                placeholder="Enter problem"
                style="flex:1;padding:10px;"
            >

            <button
                onclick="sendMessage()"
                style="background:green;color:white;border:none;padding:10px 20px;"
            >
                Send
            </button>

        </div>

    </div>

    <!-- Footer -->

    <div style="background:green;color:white;text-align:center;padding:10px;margin-top:20px;">
        Ayurvedic Website
    </div>

    <script src="script.js"></script>

</body>
</html>
```

script:

```
function sendMessage()
{
    let input = document.getElementById("userInput");

    let message = input.value.toLowerCase();

    let chatbox = document.getElementById("chatbox");

    // User Message (Right Side)

    chatbox.innerHTML +=
    `<div style="
        background:#c8f7c5;
        padding:10px;
        margin:10px;
        border-radius:10px;
        width:fit-content;
        margin-left:auto;
        text-align:right;
    ">
        ${message}
    </div>`;

    let response = "";

    // Rule Based Replies

    if(message.includes("cold"))
    {
        response = "Drink Tulsi and Ginger tea.";
    }
    else if(message.includes("cough"))
    {
        response = "Take honey with warm water.";
    }
    else if(message.includes("fever"))
    {
        response = "Drink herbal kadha and stay hydrated.";
    }
    else if(message.includes("headache"))
    {
        response = "Apply sandalwood paste and take rest.";
    }
    else
    {
        response = "Sorry, I know only basic Ayurvedic remedies.";
    }

    // Bot Message (Left Side)

    chatbox.innerHTML +=
    `<div style="
        background:#ffd6d6;
        padding:10px;
        margin:10px;
        border-radius:10px;
        width:fit-content;
    ">
        ${response}
    </div>`;

    input.value = "";

    // Auto Scroll

    chatbox.scrollTop = chatbox.scrollHeight;
}
```

```
sudo apt install nginx -y

 sudo systemctl start nginx

 sudo systemctl enable nginx
```

```
sudo rm /var/www/html/index.nginx-debian.html
sudo cp ~/index.html /var/www/html/
sudo cp ~/script.js /var/www/html/
```
