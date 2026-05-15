Here is your clean updated documentation with the corrected Step 3 (UI-based VM connection) and full hosting flow.
________________________________________
🚀 Hosting a Static Website on Azure VM (Ubuntu + Nginx)
________________________________________
1. Create Virtual Machine (Azure Portal)
Step 1: Create VM
•	Go to Azure Portal
•	Click Create a resource → Virtual Machine
•	Select:
o	Image: Ubuntu 22.04 / 24.04 LTS
o	Size: B1s (recommended for student plan)
o	Authentication: SSH public key
________________________________________
Step 2: Networking Configuration (VERY IMPORTANT)
In Networking tab, ensure:
•	Public IP: Enabled
•	Inbound Ports:
o	✅ SSH (22)
o	✅ HTTP (80) ← REQUIRED
o	(Optional) HTTPS (443)
👉 Make sure Network Security Group (NSG) allows port 80.
________________________________________
2. Create VM
Click:
Review + Create → Create
Wait for deployment to complete.
________________________________________
3. Connect to VM (Using Azure UI - NO COMMAND REQUIRED)
Instead of using SSH manually:
Steps:
1.	Go to Azure Portal
2.	Open your Virtual Machine
3.	Click Connect
4.	Select SSH
5.	Click Open in browser / Native SSH option
👉 Azure will open a terminal directly in browser OR give guided login.
Now you are inside your VM shell.
________________________________________
4. Update System Packages
sudo apt update && sudo apt upgrade -y
________________________________________
5. Install Nginx Web Server
sudo apt install nginx -y
________________________________________
6. Start & Enable Nginx
sudo systemctl start nginx
sudo systemctl enable nginx
Check status:
sudo systemctl status nginx
________________________________________
7. (Optional) Firewall Configuration
Check firewall:
sudo ufw status
If enabled:
sudo ufw allow 'Nginx Full'
sudo ufw allow 80
________________________________________
8. Deploy Static Website
Nginx default folder:
/var/www/html
Remove default page:
sudo rm /var/www/html/index.nginx-debian.html
Create your website:
sudo nano /var/www/html/index.html
Paste:
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>My Azure Hosted Website</title>

  <style>
    body {
      margin: 0;
      font-family: Arial, sans-serif;
      background: #f4f7fb;
    }

    /* Header */
    .header {
      background: #0078D4;
      color: white;
      padding: 20px;
      text-align: center;
      font-size: 28px;
      font-weight: bold;
    }

    /* Navigation Buttons */
    .nav {
      display: flex;
      justify-content: center;
      background: #ffffff;
      padding: 15px;
      gap: 15px;
      box-shadow: 0 2px 5px rgba(0,0,0,0.1);
    }

    .nav button {
      padding: 10px 20px;
      border: none;
      background: #0078D4;
      color: white;
      border-radius: 8px;
      cursor: pointer;
      transition: 0.3s;
    }

    .nav button:hover {
      background: #005a9e;
    }

    /* Main Layout */
    .container {
      display: flex;
      margin: 20px;
      gap: 20px;
    }

    /* Left Panel */
    .sidebar {
      width: 25%;
      background: white;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
    }

    /* Right Content */
    .content {
      width: 75%;
      background: white;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
    }

    /* Cards */
    .card {
      background: #eaf3ff;
      padding: 15px;
      margin-top: 10px;
      border-radius: 10px;
    }

    /* Footer */
    .footer {
      text-align: center;
      padding: 15px;
      margin-top: 20px;
      background: #0078D4;
      color: white;
    }

  </style>
</head>

<body>

  <!-- Header -->
  <div class="header">
    🚀 My Azure Static Website
  </div>

  <!-- Navigation Buttons -->
  <div class="nav">
    <button>Home</button>
    <button>About</button>
    <button>Services</button>
    <button>Contact</button>
  </div>

  <!-- Main Content -->
  <div class="container">

    <!-- Sidebar (Frame 1) -->
    <div class="sidebar">
      <h3>📌 Quick Info</h3>
      <p>This website is hosted on an Azure VM using Nginx.</p>

      <div class="card">
        ✔ Ubuntu Server
      </div>
      <div class="card">
        ✔ Nginx Web Server
      </div>
      <div class="card">
        ✔ Static Hosting
      </div>
    </div>

    <!-- Content Area (Frame 2) -->
    <div class="content">
      <h2>Welcome 👋</h2>
      <p>
        This is a simple static website deployed on a cloud virtual machine.
        It demonstrates how HTML, CSS, and Nginx work together.
      </p>

      <div class="card">
        <h3>💡 Features</h3>
        <ul>
          <li>Responsive layout</li>
          <li>Clickable buttons</li>
          <li>Box-style frames</li>
          <li>Clean UI design</li>
        </ul>
      </div>

      <div class="card">
        <h3>🚀 Deployment</h3>
        <p>
          Hosted using Azure VM + Ubuntu + Nginx web server.
        </p>
      </div>

      <button style="margin-top:10px; padding:10px 15px; background:#28a745; color:white; border:none; border-radius:8px;">
        Learn More
      </button>

    </div>
  </div>

  <!-- Footer -->
  <div class="footer">
    © 2026 My Azure Website | Built with Nginx
  </div>

</body>
</html>________________________________________
9. Restart Nginx
sudo systemctl restart nginx
________________________________________
10. Test Website
Inside VM:
curl http://localhost
Outside VM (Browser):
http://<YOUR_PUBLIC_IP>
________________________________________
🎉 Output
Your static website is now live using:
•	Azure VM
•	Ubuntu
•	Nginx
•	Port 80 HTTP
________________________________________
⚠️ Common Issues
•	❌ Port 80 not open → website not accessible externally
•	❌ Forgot to restart nginx
•	❌ Wrong file path (/var/www/html/index.html)
•	❌ Using HTTPS instead of HTTP initially
________________________________________
If you want next upgrades, I can help you with:
🚀 Add HTTPS (SSL using Let’s Encrypt)
🚀 Deploy React/Angular frontend
🚀 Connect backend (Node.js + API)
🚀 Custom domain setup
Just tell 👍

