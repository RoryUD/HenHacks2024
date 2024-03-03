import React, { useState } from "react";
import "./App.css";
import { Button, Container, Row, Col } from "react-bootstrap";
import axios from "axios";

function App(): JSX.Element {
    const [responseText, setResponseText] = useState<string>("");

    const handleClick = () => {
        axios.get("http://localhost:3000/homepage")
            .then(response => {
                const { message } = response.data;
                setResponseText(message);
            })
            .catch(error => {
                console.error("Error:", error);
            });
    };

    return (
        <div className="App">
            <h1>this is header text</h1>
            <header className="App-header">
                UD CISC275 with React Hooks and TypeScript
            </header>
            <p>
                Edit <code>src/App.tsx</code> and save. This page will
                automatically reload. Also im Alex Hoy, Hello World.
            </p>
            <Container>
                <Row>
                    <Col>
                        <div
                            style={{
                                height: "40px",
                                width: "30px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                    <Col>
                        Why this bird is angry:
                        <ol>
                            <li>Eggs got taken</li>
                            <li>He is red</li>
                            <li>He is frowning</li>
                        </ol>
                        <div
                            style={{
                                height: "30px",
                                width: "40px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                </Row>
            </Container>
            <Button onClick={handleClick}>
                Get Message from C++ Backend
            </Button>
            <p> {responseText && (
                <div>Message: {responseText}</div>
            )}</p>
        </div>
    );
}

export default App;
