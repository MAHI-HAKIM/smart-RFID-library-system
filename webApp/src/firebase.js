import firebase from 'firebase/compat/app';
import 'firebase/compat/auth';
import 'firebase/compat/database';
import 'firebase/compat/firestore';

const app = firebase.initializeApp(
    {
        apiKey: "",
        authDomain: "",
        databaseURL: "",
        projectId: "",
        storageBucket: "",
        messagingSenderId: "]",
        appId: "",
        measurementId: ""
    }
)

export const auth = app.auth();
export const database = firebase.database();
export const firestore = firebase.firestore();
export default app;
