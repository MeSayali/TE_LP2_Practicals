# Azure MERN E-Commerce Website Deployment Guide

This guide explains how to deploy the MERN E-Commerce Website on an Azure Virtual Machine using:

- Node.js
- PM2
- Nginx
- MongoDB Atlas
- Vite Frontend Build

---

# 1. Connect to Azure VM if doing from terminal of PC

Open Command Prompt:

```cmd
cd Downloads
```

```cmd
ssh -i VM1_key.pem azureuser@20.255.56.127
```

---

# 2. Update Server

```bash
sudo apt update && sudo apt upgrade -y
```

### Expected Output

```bash
Reading package lists... Done
```

---

# 3. Install Node.js

```bash
curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
```

```bash
sudo apt install -y nodejs
```

Check version:

```bash
node -v
```

### Expected Output

```bash
v20.x.x
```

---

# 4. Install Git and Nginx

```bash
sudo apt install git nginx -y
```

### Expected Output

```bash
Setting up nginx ...
```

---

# 5. Clone Project

```bash
cd ~
```

```bash
git clone https://github.com/sanskruti885/E_commerce_website
```

### Expected Output

```bash
Cloning into 'E_commerce_website'...
```

---

# 6. Enter Project

```bash
cd E_commerce_website
```

Check folders:

```bash
ls
```

### Expected Output

```bash
backend  frontend
```

---

# 7. Install Backend Dependencies

```bash
cd backend
```

```bash
npm install
```

### Expected Output

```bash
added packages...
found 0 vulnerabilities
```

---

# 8. Configure Environment Variables

Create .env file:

```bash
nano .env
```

Add:

```env
PORT=5001
MONGO_URI=mongodb+srv://sanskruti:san885patil@cluster0.xzhqa.mongodb.net/ecommerce?retryWrites=true&w=majority&appName=Cluster0
JWT_SECRET=mysecret
```

Save:
- CTRL + O
- ENTER
- CTRL + X

---

# 9. Install PM2

```bash
sudo npm install -g pm2
```

### Expected Output

```bash
added packages...
```

---

# 10. Start Backend

```bash
pm2 start server.js --name backend
```

### Expected Output

```bash
status online
```

Check:

```bash
pm2 list
```

### Expected Output

```bash
┌────┬──────────┬─────────┐
│ id │ name     │ status  │
├────┼──────────┼─────────┤
│ 0  │ backend  │ online  │
└────┴──────────┴─────────┘
```

---

# 11. Test Backend API

```bash
curl http://localhost:5001/api/products
```

### Expected Output

```json
[
  {
    "_id": "...",
    "name": "Product Name",
    "price": 1000
  }
]
```

---

# 12. Setup Frontend

Go to frontend:

```bash
cd ../frontend
```

Install dependencies:

```bash
npm install
```

### Expected Output

```bash
added packages...
```

---

# 13. Build Frontend

```bash
npm run build
```

### Expected Output

```bash
dist folder created successfully
```

Check:

```bash
ls
```

### Expected Output

```bash
dist
```

---

# 14. Configure Nginx

Open nginx config:

```bash
sudo nano /etc/nginx/sites-available/app
```

Paste:

```nginx
server {
    listen 80;

    server_name YOUR_PUBLIC_IP;

    root /home/azureuser/E_commerce_website/frontend/dist;
    index index.html;

    location / {
        try_files $uri /index.html;
    }

    location /api/ {
        proxy_pass http://localhost:5001;

        proxy_http_version 1.1;

        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';

        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }
}
```

Save:
- CTRL + O
- ENTER
- CTRL + X

---

# 15. Enable Nginx Config

```bash
sudo ln -s /etc/nginx/sites-available/app /etc/nginx/sites-enabled/
```

If you see:

```bash
File exists
```

that is okay.

---

# 16. Remove Default Nginx Site

```bash
sudo rm /etc/nginx/sites-enabled/default
```

---

# 17. Test Nginx Configuration

```bash
sudo nginx -t
```

### Expected Output

```bash
nginx: the configuration file /etc/nginx/nginx.conf syntax is ok
nginx: configuration file /etc/nginx/nginx.conf test is successful
```

---

# 18. Restart Nginx

```bash
sudo systemctl restart nginx
```

---

# 19. Give Permissions

```bash
sudo chmod 755 /home/azureuser
```

```bash
sudo chmod -R 755 /home/azureuser/E_commerce_website
```

---

# 20. Restart Nginx Again

```bash
sudo systemctl restart nginx
```

---

# 21. Test Nginx Again

```bash
sudo nginx -t
```

### Expected Output

```bash
syntax is ok
test is successful
```

---

# 22. Restart Nginx

```bash
sudo systemctl restart nginx
```

---

# 23. Azure Networking

Go to Azure Portal:

- Virtual Machine
- Networking
- Inbound Port Rules

Allow:

| Port | Protocol | Action |
|------|-----------|--------|
| 80   | TCP       | Allow  |

---

# 24. Open Website

In browser:

```text
http://20.255.56.127
```

---

# 25. Useful Commands

Restart backend:

```bash
pm2 restart backend
```

View logs:

```bash
pm2 logs backend
```

Restart nginx:

```bash
sudo systemctl restart nginx
```

Check nginx status:

```bash
sudo systemctl status nginx
```

---

# 26. Common Errors

## Blank Page After Build

Run:

```bash
npm run build
```

Make sure `dist` folder exists.

---

## Default Nginx Page Appears

Remove default config:

```bash
sudo rm /etc/nginx/sites-enabled/default
```

Restart nginx.

---

## 403 Forbidden

Fix permissions:

```bash
sudo chmod 755 /home/azureuser
sudo chmod -R 755 /home/azureuser/E_commerce_website
```

---

## API Not Working

Frontend should use:

```javascript
const API_BASE = "/api";
```

NOT:

```javascript
const API_BASE = "http://localhost:5001/api";
```

---

# Deployment Completed

Your MERN E-Commerce Website is now deployed using:

- Nginx for frontend hosting
- Express backend on port 5001
- MongoDB Atlas database
- PM2 process manager
- Vite production build
