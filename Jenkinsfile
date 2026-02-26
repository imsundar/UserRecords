pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Syntax Check') {
            steps {
                echo 'Checking Python syntax...'
                sh 'python3 -m py_compile user.py'
                sh 'python3 -m py_compile user_store.py'
                sh 'python3 -m py_compile main.py'
            }
        }

        stage('Run') {
            steps {
                echo 'Running application...'
                sh 'python3 main.py'
            }
        }
    }

    post {
        failure {
            script {
                // Fetch console log via Jenkins API with auth
                def buildUrl = env.BUILD_URL
                def consoleLog = sh(
                    script: "curl -s -u admin:df9a744784b84816b56b24e16e929512 ${buildUrl}consoleText || echo 'Could not fetch console log'",
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
