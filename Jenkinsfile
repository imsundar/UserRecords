pipeline {
    agent any

    stages {
        stage('Setup') {
            steps {
                echo 'Installing build tools...'
                sh 'apt-get update -qq && apt-get install -y -qq g++ > /dev/null 2>&1'
            }
        }

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build') {
            steps {
                echo 'Compiling C++ project...'
                sh 'g++ -std=c++17 -Wall -Wextra -o user_records main.cpp User.cpp UserStore.cpp 2>&1 | tee build_output.log'
            }
        }

        stage('Test') {
            steps {
                echo 'Running executable as a smoke test...'
                sh './user_records'
            }
        }
    }

    post {
        failure {
            script {
                // Fetch console log via Jenkins API (sandbox-safe)
                def buildUrl = env.BUILD_URL
                def consoleLog = sh(
                    script: "curl -s ${buildUrl}consoleText || echo 'Could not fetch console log'",
                    returnStdout: true
                ).trim()

                def payload = groovy.json.JsonOutput.toJson([
                    console_log : consoleLog,
                    repo_url    : 'https://github.com/imsundar/UserRecords',
                    branch      : 'main',
                    build_id    : env.BUILD_NUMBER,
                    job_name    : env.JOB_NAME
                ])
                httpRequest(
                    httpMode       : 'POST',
                    url            : 'http://3.87.229.188:5001/analyze',
                    contentType    : 'APPLICATION_JSON',
                    requestBody    : payload
                )
            }
        }
    }
}
