pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build') {
            steps {
                echo 'Compiling C++ project...'
                sh 'g++ -std=c++17 -Wall -Wextra -o user_records main.cpp User.cpp UserStore.cpp'
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
                def buildLog = currentBuild.rawBuild.getLog(500).join('\n')
                def payload = groovy.json.JsonOutput.toJson([
                    job   : env.JOB_NAME,
                    build : env.BUILD_NUMBER,
                    status: currentBuild.currentResult,
                    log   : buildLog
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
