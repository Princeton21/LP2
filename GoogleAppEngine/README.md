# Creating and Deploying a Simple Node.js App to Google App Engine
In this tutorial, we will walk through the steps to create a simple Node.js application using Express and deploy it to Google App Engine.

## Prerequisites
- Basic knowledge of Node.js and npm (Node Package Manager).
- Google Cloud SDK installed on your system.
- A Google Cloud project with billing enabled.


### Step 1: Set Up a New Node.js Project
Create a new directory for your project and navigate to it in your terminal.
Initialize a new Node.js project by running the following command:
csharp
Copy code
npm init -y
This will create a new package.json file with default values.
### Step 2: Install Dependencies
Install Express, a popular Node.js web framework, using the following command:
Copy code
npm install express
### Step 3: Create the Application Code
Create a new file called index.js and open it in a text editor.
Copy and paste the following code into index.js:
javascript
Copy code
``` 
    const express = require('express');
    const app = express();
    
    app.get('/', (req, res) => {
      res.send('Hello, World!');
    });

    const PORT = process.env.PORT || 8080;
    app.listen(PORT, () => {
      console.log(`Server listening on port ${PORT}`);
    });
```
### Step 4: Create the App Engine Configuration File
Create a new file called app.yaml and open it in a text editor.

Copy and paste the following content into app.yaml:

yaml
Copy code

```runtime: nodejs14```

This specifies the Node.js runtime version to be used by App Engine.

### Step 5: Deploy the Application to Google App Engine
Initialize a new App Engine project by running the following command:
lua
Copy code
gcloud app create
This command will prompt you to select a region for your App Engine project. Choose the region that is closest to your intended audience or leave it as the default.
Set the project ID for your App Engine project using the following command:
arduino
Copy code

```gcloud config set project YOUR_PROJECT_ID```

Replace YOUR_PROJECT_ID with the actual ID of your Google Cloud project.
Deploy your Node.js app to App Engine by running the following command:
Copy code

```gcloud app deploy```

It may take a few minutes for the deployment to finish. Once it's done, you will see a message with the URL of your deployed app.
### Step 6: Test the Deployed Application
Visit the URL provided in the deployment message to access your deployed app.
You should see a "Hello, World!" message displayed in your browser.
Congratulations! You have successfully created a simple Node.js application and deployed it to Google App Engine.