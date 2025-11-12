"""
Spam Email Classifier Project
Author: Your Name
Run Command: python spam_project.py

Description:
This project trains a simple machine learning model using Naive Bayes
to classify text messages or emails as SPAM or NOT SPAM.
It uses a built-in demo dataset (no external files needed).
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.pipeline import Pipeline
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import joblib
import sys

# ------------------------------
# Step 1: Create demo dataset
# ------------------------------
def load_data():
    data = [
        ("Win money now!!!", 1),
        ("Exclusive offer for you, limited time only!", 1),
        ("Congratulations! You have won a free iPhone!", 1),
        ("Claim your $500 cash prize here!", 1),
        ("Your account is locked. Click to verify now.", 1),
        ("Urgent! You won a lottery. Respond immediately.", 1),
        ("You have been selected for a cash reward!", 1),
        ("Let's meet tomorrow for project discussion.", 0),
        ("Your appointment is confirmed at 10 AM.", 0),
        ("Can you send the assignment file?", 0),
        ("Don't forget about our meeting tomorrow.", 0),
        ("Please review the attached report.", 0),
        ("Lunch at 1 PM today?", 0),
        ("Call me when you reach home.", 0),
        ("Team meeting rescheduled to 3 PM.", 0),
        ("Hi,can you send me the notes from class?", 0),
        ("Please bring your ID card tomorrow.", 0),
        ("Are you free for a quick call this evening?", 0),
        ("You've been pre-approved for a credit card with $10,000 limit!", 1),
        ("Congratulations! You've won a free vacation to Dubai!", 1),
        ("Limited time offer! Buy 1 get 1 free!", 1),
        ("Your loan has been approved. Click here to claim.", 1),
        ("Act fast! Only 2 hours left to claim your reward.", 1),
        ("Earn ₹10,000 per week working from home!", 1),
        ("Your Netflix account is suspended. Update your payment now.", 1),
        ("You have received a parcel. Verify your details here.", 1),
        ("Hot singles are waiting to chat with you!", 1),
        ("Get cheap medicines online. No prescription required!", 1),
        ("Exclusive deal! Save 80% on all electronics.", 1),
        ("You are selected for a free gift card worth ₹5000!", 1),
        ("Your OTP is 654321. Do not share with anyone. (Fake OTP scam)", 1),
        ("Congratulations! You are our lucky customer today!", 1),
        ("Get rich quick! Learn how to make ₹1 lakh per month.", 1),
        ("Final notice: Your car insurance expires today.", 1),
        ("Win a brand new car! Enter your details now.", 1),
        ("This is not a scam! Claim your reward immediately!", 1),
        ("Dear user, your bank account is at risk. Verify now.", 1),
        ("Your mobile number has won ₹5,00,000 in lucky draw.", 1),
        ("Limited seats available for free crypto webinar!", 1),
        ("You are chosen to participate in our rewards program.", 1),
        ("Hurry! Sale ends midnight. Don’t miss out.", 1),
        ("Get instant followers and likes on Instagram!", 1),
        ("Your payment failed. Re-enter your card information.", 1),
        ("Can you share the project report before class?", 0),
        ("I’ll join the meeting in 5 minutes.", 0),
        ("Please send me the updated timetable.", 0),
        ("Let’s go out for dinner tonight.", 0),
        ("I’ve attached the notes you asked for.", 0),
        ("The server is down. Please check it.", 0),
        ("Don’t forget to submit your assignment by tomorrow.", 0),
        ("Good morning team, let’s meet in conference room A.", 0),
        ("Can we schedule a quick call this afternoon?", 0),
        ("Happy birthday! Hope you have a great day.", 0),
        ("I’ll be working from home tomorrow.", 0),
        ("Please confirm your attendance for the workshop.", 0),
        ("Can you forward the email to the new intern?", 0),
        ("Let’s discuss the proposal after lunch.", 0),
        ("Thank you for your help with the presentation.", 0),
        ("I received your message. I’ll get back to you soon.", 0),
        ("Your package has been delivered successfully.", 0),
        ("See you at the bus stop in 10 minutes.", 0),
        ("Do you have any updates on the project status?", 0),
        ("Meeting postponed to 4 PM due to technical issues.", 0),
        ("Can you please resend the file? I can’t open it.", 0),
        ("Good night! Don’t forget to set the alarm.", 0),
        ("Please collect your ID card from the admin office.", 0),
        ("Let’s prepare for the presentation together.", 0),
        ("The weather is nice today. Let’s go for a walk.", 0),
        ("Let’s meet at the library to study.", 0),
        ("The results will be announced next week.", 0)
    ]
    # optional: deduplicate if needed
    texts, labels = zip(*data)
    return list(texts), list(labels)

# ------------------------------
# Step 2: Build pipeline model
# ------------------------------
def build_pipeline():
    return Pipeline([
        ('vect', CountVectorizer(stop_words='english')),
        ('tfidf', TfidfTransformer()),
        ('clf', MultinomialNB())
    ])

# ------------------------------
# Step 3: Train and evaluate model
# ------------------------------
def train_and_evaluate(X, y, test_size=0.2, random_state=42):
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=test_size, random_state=random_state, stratify=y
    )
    model = build_pipeline()
    print("\nTraining the model...")
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)

    print("\n✅ Model Training Complete!")
    print("\n📊 Accuracy:", round(accuracy_score(y_test, y_pred), 3))
    print("\n📈 Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
    print("\n🧾 Classification Report:\n", classification_report(y_test, y_pred, zero_division=0))
    return model

# ------------------------------
# Step 4: Save model
# ------------------------------
def save_model(model, path="spam_model.joblib"):
    joblib.dump(model, path)
    print(f"\n💾 Model saved as {path}")

# ------------------------------
# Step 5: Interactive testing
# ------------------------------
def test_model(model):
    print("\n📨 Type any message to check if it's SPAM or NOT SPAM.")
    print("Type 'exit' to quit.\n")
    try:
        while True:
            msg = input(">>> ").strip()
            if msg.lower() == "exit":
                print("\n👋 Exiting Spam Classifier. Goodbye!")
                break
            pred = model.predict([msg])[0]
            print("Prediction:", "🚨 SPAM" if pred == 1 else "✅ NOT SPAM")
    except (KeyboardInterrupt, EOFError):
        print("\n\n👋 Exiting Spam Classifier. Goodbye!")
        sys.exit(0)

# ------------------------------
# Main execution
# ------------------------------
if __name__ == "__main__":
    X, y = load_data()
    model = train_and_evaluate(X, y)
    save_model(model)
    test_model(model)
