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
                echo 'Running build...'
                // add your build commands here, e.g.:
                // sh 'npm install && npm run build'
            }
        }

        stage('Test') {
            steps {
                echo 'Running tests...'
                // sh 'npm test'
            }
        }
    }

    post {
        always {
            script {
                def buildLog = currentBuild.rawBuild.getLog(100).join('\n')
                def payload = groovy.json.JsonOutput.toJson([
                    job   : env.JOB_NAME,
                    build : env.BUILD_NUMBER,
                    status: currentBuild.currentResult,
                    log   : buildLog
                ])
                httpRequest(
                    httpMode       : 'POST',
                    url            : 'http://your-webserver.com/build-hook',
                    contentType    : 'APPLICATION_JSON',
                    requestBody    : payload
                )
            }
        }
    }
}
