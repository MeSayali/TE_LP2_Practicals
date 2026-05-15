Event Registration System Deployment on
Microsoft Azure
Project Name
Event Registration System
GitHub Repository
EventRegistration-System GitHub Repository
Aim
To deploy the Event Registration System project on a Microsoft Azure Virtual Machine using:
• Ubuntu Linux VM
• Node.js
• MongoDB Atlas
• PM2 Process Manager
• Nginx Web Server
Technologies Used
• Frontend: React.js, HTML, CSS, JavaScript
• Backend: Node.js, Express.js
• Database: MongoDB Atlas
• Server: NGINX
• Process Manager: PM2
• Cloud Platform: Microsoft Azure
• Version Control: Git & GitHub
Azure VM Configuration
• OS: Ubuntu 24.04 LTS
• VM Size: Standard B1s
• Authentication Type: SSH Key Pair
Deployment Steps
Step 1: Connect to Azure VM
cd Downloads
ssh -i VM1_key.pem azureuser@<PUBLIC-IP>
Step 2: Update Ubuntu Packages
sudo apt update && sudo apt upgrade -y
Step 3: Install Node.js
curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E
bash -
sudo apt install -y nodejs
Check Version
node -v
npm -v
Step 4: Install Git and Nginx
sudo apt install git nginx -y
Step 5: Clone GitHub Repository
cd ~
git clone https://github.com/GauriWagh1109/EventRegistration-
System.git
Open Project Folder
cd EventRegistration-System
Backend Deployment
Step 6: Install Backend Dependencies
npm install
Step 7: Create Environment Variables
Create .env file:
nano .env
Add:
PORT=4000
MONGO_URI=your_mongodb_connection_string
Step 8: Install PM2
sudo npm install -g pm2
Step 9: Start Backend Server
pm2 start server.js --name backend
Check Running Process
pm2 list
Save PM2 Process
pm2 save
Step 10: Test Backend
curl http://localhost:4000/registrations
Sample Output
[
{
"_id": "12345",
"name": "Gauri",
"email": "gauri@gmail.com",
"college": "ABC College",
"event": "Coding Competition"
}
]
Frontend Deployment
Step 11: Build React Frontend
cd ~/EventRegistration-System/frontend
npm install
npm run build
Step 12: Configure Nginx
Create Nginx Configuration:
sudo nano /etc/nginx/sites-available/app
Add Configuration:
server {
listen 80 default_server;
server_name _;
root /home/s24ce016/EventRegistration-System/frontend/
build;
index index.html;
location / {
try_files $uri /index.html;
}
location /registrations {
proxy_pass http://localhost:4000;
}
}
Step 13: Enable Nginx Configuration
sudo ln -s /etc/nginx/sites-available/app /etc/nginx/sites-
enabled/
Remove Default Configuration
sudo rm /etc/nginx/sites-enabled/default
Step 14: Fix Folder Permissions
If you get permission denied or 500 Internal Server Error:
sudo chmod 755 /home/s24ce016
sudo chmod -R 755 /home/s24ce016/EventRegistration-System
sudo chmod -R 755 /home/s24ce016/EventRegistration-System/
frontend/build
Step 15: Test and Restart Nginx
sudo nginx -t
sudo systemctl restart nginx
Step 16: Allow HTTP Port in Azure
Go to Azure VM Networking Settings:
• Add Inbound Rule
• Port: 80
• Protocol: HTTP
• Action: Allow
Errors Faced During Deployment
1. 500 Internal Server Error
Cause
Incorrect Nginx root path and permission issues.
Solution
Updated Nginx configuration with correct React build folder path:
root /home/s24ce016/EventRegistration-System/frontend/build;
Also fixed folder permissions using chmod.
2. Permission Denied Error
Cause
Nginx user (www-data) could not access files inside /home/s24ce016.
Error Log
Permission denied
Solution
sudo chmod 755 /home/s24ce016
sudo chmod -R 755 /home/s24ce016/EventRegistration-System
3. Rewrite or Internal Redirection Cycle Error
Cause
Incorrect React routing configuration in Nginx.
Error
rewrite or internal redirection cycle while internally
redirecting to "/index.html"
Solution
Updated routing configuration:
location / {
try_files $uri /index.html;
}
4. Backend Connection Error
Cause
Incorrect backend port used in Nginx configuration.
Solution
Backend was running on port 4000, so updated:
proxy_pass http://localhost:4000;
Final Output
http://20.244.14.63/
The Event Registration System was successfully deployed on Microsoft Azure using Ubuntu VM,
PM2, MongoDB Atlas, and Nginx.
